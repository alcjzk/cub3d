/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/08/03 14:27:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
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

void	draw_frame(t_view *self, t_scene *scene)
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
	draw_background(&self->frame, scene);
	draw_frame(self, scene);
}
