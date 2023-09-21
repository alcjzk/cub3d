/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:49:08 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 17:07:16 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "bool.h"
#include "ray.h"

static void	calc_deltadistance(t_ray *self, t_player *player)
{
	if (player->raydir.x == 0)
		self->delta_dist.x = INFINITY;
	else
		self->delta_dist.x = 1 / player->raydir.x;
	if (player->raydir.y == 0)
		self->delta_dist.y = INFINITY;
	else
		self->delta_dist.y = 1 / player->raydir.y;
	if (self->delta_dist.x < 0)
		self->delta_dist.x *= -1.0f;
	if (self->delta_dist.y < 0)
		self->delta_dist.y *= -1.0f;
}

static void	calc_steps(t_ray *self, t_player *player)
{
	if (player->raydir.x >= 0)
	{
		self->step.x = 1;
		self->side_dist.x = self->map_pos.x + 1.0f - player->position.x;
		self->side_dist.x *= self->delta_dist.x;
	}
	else
	{
		self->step.x = -1;
		self->side_dist.x = player->position.x - self->map_pos.x;
		self->side_dist.x *= self->delta_dist.x;
	}
	if (player->raydir.y >= 0)
	{
		self->step.y = 1;
		self->side_dist.y = self->map_pos.y + 1.0f - player->position.y;
		self->side_dist.y *= self->delta_dist.y;
	}
	else
	{
		self->step.y = -1;
		self->side_dist.y = player->position.y - self->map_pos.y;
		self->side_dist.y *= self->delta_dist.y;
	}
}

void	ray_cast(t_ray *self, t_scene *scene)
{
	while (TRUE)
	{
		if (self->side_dist.x < self->side_dist.y)
		{
			self->side_dist.x += self->delta_dist.x;
			self->map_pos.x += self->step.x;
			if (self->step.x < 0)
				self->side = SIDE_EAST;
			else
				self->side = SIDE_WEST;
		}
		else
		{
			self->side_dist.y += self->delta_dist.y;
			self->map_pos.y += self->step.y;
			if (self->step.y < 0)
				self->side = SIDE_NORTH;
			else
				self->side = SIDE_SOUTH;
		}
		if (ray_at_end(self, &scene->map))
			break ;
	}
	self->perp_wall_dist = ray_perpendicular_wall_distance(self);
}

void	ray_init(t_ray *self, t_scene *scene)
{
	self->map_pos.x = (int)scene->player.position.x;
	self->map_pos.y = (int)scene->player.position.y;
	calc_deltadistance(self, &scene->player);
	calc_steps(self, &scene->player);
}
