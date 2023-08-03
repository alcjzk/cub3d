/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:39:38 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/03 14:26:48 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "state.h"
#include "line.h"

void	line_init(t_line *self, t_ray *ray)
{
	if (ray->perp_wall_dist == 0)
		ray->perp_wall_dist = 1;
	self->height = WINDOW_HEIGHT / ray->perp_wall_dist;
	self->start = -self->height / 2 + WINDOW_HEIGHT / 2;
	if (self->start < 0)
		self->start = 0;
	self->end = self->height / 2 + WINDOW_HEIGHT / 2;
	if (self->end >= WINDOW_HEIGHT)
		self->end = WINDOW_HEIGHT - 1;
}

void	line_draw_color(t_line *self, t_view *view, int x, t_ray *ray)
{
	int	y;

	if (ray->side == 1)
		self->color = (t_color)0x00FF0000;
	else
		self->color = (t_color)0x000000FF;
	y = self->start;
	while (y <= self->end)
		image_put_pixel(&view->frame, x, y++, self->color);
}
