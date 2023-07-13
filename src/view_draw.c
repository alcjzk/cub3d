/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/13 15:50:09 by emajuri          ###   ########.fr       */
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
		ray->delta_dist.x = ft_abs(1 / player->raydir.x);
	if (player->raydir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = ft_abs(1 / player->raydir.y);
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
		if (scene->map[(int)ray->map_pos.y][(int)ray->map_pos.x] > 0)
			ray->hit = 1;
	}
}

void	calc_line(t_ray *ray, t_line *line)
{
	line->height = (WINDOW_HEIGHT / ray->perp_wall_dist);
	line->start = -line->height / 2 + WINDOW_HEIGHT / 2;
	if (line->start < 0)
		line->start = 0;
	line->end = line->height / 2 + WINDOW_HEIGHT / 2;
	if (line->end >= WINDOW_HEIGHT)
		line->end = WINDOW_HEIGHT - 1;
	
}

void	draw_color_line(t_view *self, t_line *line, int x)
{
	int	y;

	y = line->start;
	while (y <= line->end)
		image_put_pixel(self->back, x, y++, line->color);
}

#include <stdio.h>

void	draw_line(t_view *self, t_scene *scene, int x)
{
	t_ray	ray;
	t_line	line;

	ray = (t_ray){};
	calc_deltadistance(&scene->player, &ray);
	calc_steps(&scene->player, &ray);
	dda(scene, &ray);
	if (ray.side == horizontal)
		ray.perp_wall_dist = (ray.side_dist.x - ray.delta_dist.x);
	else
		ray.perp_wall_dist = (ray.side_dist.y - ray.delta_dist.y);
	line = (t_line){};
	// printf("side: %i\n", ray.side);
	// printf("xside: %f, xdelta: %f\n", ray.side_dist.x, ray.delta_dist.x);
	// printf("yside: %f, ydelta: %f\n", ray.side_dist.y, ray.delta_dist.y);
	// printf("perpwall: %f\n", ray.perp_wall_dist);
	calc_line(&ray, &line);
	// printf("height: %d, start: %d, end: %d\n", line.height, line.start, line.end);
	exit(0);
	if (ray.side == 1)
		line.color = (t_color)0x00FF0000;
	else
		line.color = (t_color)0x0000FF00;
	draw_color_line(self, &line, x);
}

void	draw_frame(t_view *self, t_scene *scene)
{
	int				x;
	t_player	*player;

	x = 0;
	player = &scene->player;
	player->plane.y = 0.66f;
	while (x < WINDOW_WIDTH)
	{
		player->camera.x = 2 * x / (float)WINDOW_WIDTH - 1;
		player->raydir = vec2f_add(player->direction, 
							vec2f_mul(player->plane, player->camera));
		draw_line(self, scene, x);
		x++;
	}
}

void	view_draw(t_view *self, t_scene *scene)
{
	draw_background(self->back, scene);
	// Draw world
	draw_frame(self, scene);
	view_swap_buffers(self);
	mlx_put_image_to_window(
		self->window->mlx,
		self->window->window,
		self->front->img,
		0, 0);
}
