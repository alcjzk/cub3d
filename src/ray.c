/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:49:08 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/21 14:56:39 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

static void	calc_deltadistance(t_ray *self, t_player *player)
{
	if (player->raydir.x == 0)
		self->delta_dist.x = 1e30;
	else
		self->delta_dist.x = 1 / player->raydir.x;
	if (player->raydir.y == 0)
		self->delta_dist.y = 1e30;
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

static void	calc_perp_wall_dist(t_ray *self)
{
	if (self->side == EW)
		self->perp_wall_dist = (self->side_dist.x - self->delta_dist.x);
	else
		self->perp_wall_dist = (self->side_dist.y - self->delta_dist.y);
}

void	ray_cast(t_ray *self, t_scene *scene)
{
	while (!self->hit)
	{
		if (self->side_dist.x < self->side_dist.y)
		{
			self->side_dist.x += self->delta_dist.x;
			self->map_pos.x += self->step.x;
			self->side = EW;
		}
		else
		{
			self->side_dist.y += self->delta_dist.y;
			self->map_pos.y += self->step.y;
			self->side = NS;
		}
		if (scene->map[(int)self->map_pos.y][(int)self->map_pos.x] > '0')
			self->hit = 1;
	}
	calc_perp_wall_dist(self);
}

void	ray_init(t_ray *self, t_scene *scene)
{
	self->map_pos.x = (int)scene->player.position.x;
	self->map_pos.y = (int)scene->player.position.y;
	calc_deltadistance(self, &scene->player);
	calc_steps(self, &scene->player);
}
