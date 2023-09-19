/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 20:06:13 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "view.h"
#include "ray.h"
#include "line_textured.h"

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
			image_put_pixel(
				image,
				x,
				WINDOW_HEIGHT / 2 - y - 1,
				color_add_shadow(
					scene->ceiling_color,
					(float)y / WINDOW_HEIGHT));
			image_put_pixel(
				image,
				x,
				y + WINDOW_HEIGHT / 2,
				color_add_shadow(scene->floor_color, (float)y / WINDOW_HEIGHT));
			x++;
		}
		y++;
	}
}

static void	draw_frame(t_view *self, t_scene *scene)
{
	int					x;
	t_ray				ray;
	t_line_textured		line;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		player_raydir_calc(&scene->player, x);
		ray = (t_ray){};
		ray_init(&ray, scene);
		ray_cast(&ray, scene);
		line = (t_line_textured){};
		line_textured_init(&line, scene, &ray);
		line_textured_draw(&line, self, x);
		x++;
	}
}

void	view_draw(t_view *self, t_scene *scene)
{
	draw_background(&self->frame, scene);
	draw_frame(self, scene);
}
