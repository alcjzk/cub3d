/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:00:11 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 17:07:25 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "ray.h"

_Bool	is_wall(char c)
{
	if (c == '1' || c == '2')
		return (TRUE);
	return (FALSE);
}

_Bool	ray_at_end(t_ray *self, t_map *map)
{
	if (self->map_pos.x < 0.0f || self->map_pos.y < 0.0f)
		return (TRUE);
	if (self->map_pos.x > map->width - 1.0f)
		return (TRUE);
	if (self->map_pos.y > map->height - 1.0f)
		return (TRUE);
	if (is_wall(map->map[(int)self->map_pos.y][(int)self->map_pos.x]))
		return (TRUE);
	return (FALSE);
}

float	ray_perpendicular_wall_distance(t_ray *self)
{
	if (self->side == SIDE_EAST || self->side == SIDE_WEST)
		return (self->side_dist.x - self->delta_dist.x);
	else
		return (self->side_dist.y - self->delta_dist.y);
}
