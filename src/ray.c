/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:49:08 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/18 16:49:46 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	calc_deltadistance(t_player *player, t_ray *ray)
{
	if (player->raydir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = 1 / player->raydir.x;
	if (player->raydir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = 1 / player->raydir.y;
	if (ray->delta_dist.x < 0)
		ray->delta_dist.x *= -1.0f;
	if (ray->delta_dist.y < 0)
		ray->delta_dist.y *= -1.0f;
}

void	calc_steps(t_player *player, t_ray *ray)
{
	if (player->raydir.x >= 0)
	{
		ray->step.x = 1;
		ray->side_dist.x = ray->map_pos.x + 1.0f - player->position.x;
		ray->side_dist.x *= ray->delta_dist.x;
	}
	else
	{
		ray->step.x = -1;
		ray->side_dist.x = player->position.x - ray->map_pos.x;
		ray->side_dist.x *= ray->delta_dist.x;
	}
	if (player->raydir.y >= 0)
	{
		ray->step.y = 1;
		ray->side_dist.y = ray->map_pos.y + 1.0f - player->position.y;
		ray->side_dist.y *= ray->delta_dist.y;
	}
	else
	{
		ray->step.y = -1;
		ray->side_dist.y = player->position.y - ray->map_pos.y;
		ray->side_dist.y *= ray->delta_dist.y;
	}
}

void	dda(t_scene *scene, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_pos.x += ray->step.x;
			ray->side = horizontal;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_pos.y += ray->step.y;
			ray->side = vertical;
		}
		if (scene->map[(int)ray->map_pos.y][(int)ray->map_pos.x] > '0')
			ray->hit = 1;
	}
	if (ray->side == horizontal)
		ray->perp_wall_dist = (ray->side_dist.x - ray->delta_dist.x);
	else
		ray->perp_wall_dist = (ray->side_dist.y - ray->delta_dist.y);
}
