/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/31 18:32:30 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
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
		player_raydir_calc(player, x);
		ray = (t_ray){};
		ray_init(&ray, scene);
		ray_cast(&ray, scene);
		line = (t_line){};
		line_init(&line, &ray);
		line_draw_color(&line, self, x, &ray);
		x++;
	}
}

void	view_draw(t_view *self, t_scene *scene)
{
	draw_background(self->back, scene);
	draw_frame(self, scene);
	view_swap_buffers(self);
	mlx_image_to_window(
		self->mlx,
		self->front->img,
		0, 0);
}
