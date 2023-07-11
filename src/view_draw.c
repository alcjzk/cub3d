/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 17:13:13 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

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
			image_put_pixel(image, x, y + WINDOW_HEIGHT / 2, scene->floor_color);
			x++;
		}
		y++;
	}
}

void	view_draw(t_view *self, t_scene *scene)
{
	draw_background(self->front, scene);
	// Draw world
	view_swap_buffers(self);
}
