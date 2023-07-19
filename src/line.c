/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:39:38 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/19 14:34:34 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"
#include "ray.h"
#include "view.h"

void	calc_line(t_ray *ray, t_line *line)
{
	if (ray->perp_wall_dist == 0)
		ray->perp_wall_dist = 1;
	line->height = WINDOW_HEIGHT / ray->perp_wall_dist;
	line->start = -line->height / 2 + WINDOW_HEIGHT / 2;
	if (line->start < 0)
		line->start = 0;
	line->end = line->height / 2 + WINDOW_HEIGHT / 2;
	if (line->end >= WINDOW_HEIGHT)
		line->end = WINDOW_HEIGHT - 1;
}

void	draw_color_line(t_view *self, t_line *line, int x, t_ray *ray)
{
	int	y;

	if (ray->side == 1)
		line->color = (t_color)0x00FF0000;
	else
		line->color = (t_color)0x000000FF;
	y = line->start;
	while (y <= line->end)
		image_put_pixel(self->back, x, y++, line->color);
}

void	line_draw(t_view *self, t_scene *scene, int x)
{
	t_ray	ray;
	t_line	line;

	ray = (t_ray){};
	ray_init(&ray, scene);
	ray_cast(&ray, scene);
	line = (t_line){};
	calc_line(&ray, &line);
	draw_color_line(self, &line, x, &ray);
}
