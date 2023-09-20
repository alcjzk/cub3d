/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 14:03:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "state.h"
# include "view.h"
# include "ray.h"
# include "line_textured.h"

t_color	color_add_shadow(t_color color, float amount);

void	view_draw_background(t_image *image, t_scene *scene)
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

#endif
