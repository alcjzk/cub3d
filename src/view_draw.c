/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 17:10:46 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
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

// TODO:
// Draw columns behind the sprite
// sprite { position, image }
// Draw the sprite
// Draw columns in front of the sprite

static void	draw_frame(t_view *self, t_scene *scene, float *z_buffer)
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
		z_buffer[x] = ray.perp_wall_dist;
		line = (t_line_textured){};
		line_textured_init(&line, scene, &ray);
		line_textured_draw(&line, self, x);
		x++;
	}
}

void	view_draw(t_view *self, t_scene *scene)
{
	float			*z_buffer;
	t_sprite_draw	sprite_draw;

	z_buffer = malloc(sizeof(float) * WINDOW_WIDTH);
	draw_background(&self->frame, scene);
	draw_frame(self, scene, z_buffer);
	sprite_draw_init(&sprite_draw, &self->sprite, &scene->player);
	sprite_draw_draw(&sprite_draw, z_buffer, &self->frame);
	free(z_buffer);
}
