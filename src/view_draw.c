/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/08/30 09:09:46 by tjaasalo         ###   ########.fr       */
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
	int					x;
	t_player			*player;
	t_ray				ray;
	t_line_textured		line;

	x = 0;
	player = &scene->player;
	while (x < WINDOW_WIDTH)
	{
		player_raydir_calc(player, x);
		ray = (t_ray){};
		ray_init(&ray, scene);
		ray_cast(&ray, scene);
		line = (t_line_textured){};
		line_textured_init(&line, &scene->textures, &scene->player, &ray);
		line_textured_draw(&line, self, x);
		x++;
	}
}

void	view_draw(t_view *self, t_scene *scene)
{
	draw_background(&self->frame, scene);
	draw_frame(self, scene);
}
