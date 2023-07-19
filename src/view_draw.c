/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 15:05:58 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "view.h"
#include "ray.h"
#include "line.h"

static void	draw_background(t_image *image, t_scene *scene)
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

static void	draw_frame(t_view *self, t_scene *scene)
{
	int			x;
	t_player	*player;
	t_ray		ray;
	t_line		line;

	x = 0;
	player = &scene->player;
	while (x < WINDOW_WIDTH)
	{
		player->camera.x = 2 * x / (float)WINDOW_WIDTH - 1;
		player->raydir.x = player->direction.x;
		player->raydir.x += player->plane.x * player->camera.x;
		player->raydir.y = player->direction.y;
		player->raydir.y += player->plane.y * player->camera.x;
		ray = (t_ray){};
		ray_init(&ray, scene);
		ray_cast(&ray, scene);
		line = (t_line){};
		line_init(&line, &ray);
		line_draw_color(self, &line, x, &ray);
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
