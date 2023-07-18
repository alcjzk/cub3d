/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/18 16:26:19 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "view.h"
#include "ray.h"
#include "line.h"

void	draw_background(t_image *image, t_scene *scene)
{
	int	y;
	int	x;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			image_put_pixel(image, x, y, scene->ceiling_color);
			image_put_pixel(
				image,
				x,
				y + WINDOW_HEIGHT / 2,
				scene->floor_color);
			x++;
		}
		y++;
	}
}

void	calc_deltadistance(t_player *player, t_ray *ray)
{
	if (player->raydir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = 1 / player->raydir.x;
	if (player->raydir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = 1 / player->raydir.y;
	if (ray->delta_dist.x < 0)
		ray->delta_dist.x *= -1.0f;
	if (ray->delta_dist.y < 0)
		ray->delta_dist.y *= -1.0f;
}

void	calc_steps(t_player *player, t_ray *ray)
{
	if (player->raydir.x >= 0)
	{
		ray->step.x = 1;
		ray->side_dist.x = ray->map_pos.x + 1.0f - player->position.x;
		ray->side_dist.x *= ray->delta_dist.x;
	}
	else
	{
		ray->step.x = -1;
		ray->side_dist.x = player->position.x - ray->map_pos.x;
		ray->side_dist.x *= ray->delta_dist.x;
	}
	if (player->raydir.y >= 0)
	{
		ray->step.y = 1;
		ray->side_dist.y = ray->map_pos.y + 1.0f - player->position.y;
		ray->side_dist.y *= ray->delta_dist.y;
	}
	else
	{
		ray->step.y = -1;
		ray->side_dist.y = player->position.y - ray->map_pos.y;
		ray->side_dist.y *= ray->delta_dist.y;
	}
}

void	dda(t_scene *scene, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step.x;
			ray->side = horizontal;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step.y;
			ray->side = vertical;
		}
		if (scene->map[(int)ray->map_pos.y][(int)ray->map_pos.x] > '0')
			ray->hit = 1;
	}
}

void	calc_line(t_ray *ray, t_line *line)
{
	if (ray->perp_wall_dist == 0)
		ray->perp_wall_dist = 1;
	line->height = WINDOW_HEIGHT / ray->perp_wall_dist;
	line->start = -line->height / 2 + WINDOW_HEIGHT / 2;
	if (line->start < 0)
		line->start = 0;
	line->end = line->height / 2 + WINDOW_HEIGHT / 2;
	if (line->end >= WINDOW_HEIGHT)
		line->end = WINDOW_HEIGHT - 1;
}

void	draw_color_line(t_view *self, t_line *line, int x, t_ray *ray)
{
	int	y;

	if (ray->side == 1)
		line->color = (t_color)0x00FF0000;
	else
		line->color = (t_color)0x000000FF;
	y = line->start;
	while (y <= line->end)
		image_put_pixel(self->back, x, y++, line->color);
}

void	draw_line(t_view *self, t_scene *scene, int x)
{
	t_ray	ray;
	t_line	line;

	ray = (t_ray){};
	ray.map_pos.x = (int)scene->player.position.x;
	ray.map_pos.y = (int)scene->player.position.y;
	calc_deltadistance(&scene->player, &ray);
	calc_steps(&scene->player, &ray);
	dda(scene, &ray);
	if (ray.side == horizontal)
		ray.perp_wall_dist = (ray.side_dist.x - ray.delta_dist.x);
	else
		ray.perp_wall_dist = (ray.side_dist.y - ray.delta_dist.y);
	line = (t_line){};
	calc_line(&ray, &line);
	draw_color_line(self, &line, x, &ray);
}

void	draw_frame(t_view *self, t_scene *scene)
{
	int				x;
	t_player	*player;

	x = 0;
	player = &scene->player;
	while (x < WINDOW_WIDTH)
	{
		player->camera.x = 2 * x / (float)WINDOW_WIDTH - 1;
		player->raydir.x = player->direction.x + player->plane.x * player->camera.x; 
		player->raydir.y = player->direction.y + player->plane.y * player->camera.x; 
		draw_line(self, scene, x);
		x++;
	}
}

void	view_draw(t_view *self, t_scene *scene)
{
	draw_background(self->back, scene);
	draw_frame(self, scene);
	view_swap_buffers(self);
	mlx_put_image_to_window(
		self->window->mlx,
		self->window->window,
		self->front->img,
		0, 0);
}
