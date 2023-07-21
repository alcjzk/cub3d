/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:07:59 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/21 14:58:56 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "window.h"

void	player_init(t_player *self, char dir, int y, int x)
{
	self->is_valid = TRUE;
	self->position.x = x + 0.5f;
	self->position.y = y + 0.5f;
	if (dir == 'N')
	{
		self->plane.x = 0.66f;
		self->direction.y = -1;
	}
	else if (dir == 'S')
	{
		self->plane.x = -0.66f;
		self->direction.y = 1;
	}
	else if (dir == 'W')
	{
		self->plane.y = -0.66f;
		self->direction.x = -1;
	}
	else if (dir == 'E')
	{
		self->plane.y = 0.66f;
		self->direction.x = 1;
	}
}

void	player_raydir_calc(t_player *self, int x)
{
	float	camera;

	camera = 2 * x / (float)WINDOW_WIDTH - 1;
	self->raydir.x = self->direction.x;
	self->raydir.x += self->plane.x * camera;
	self->raydir.y = self->direction.y;
	self->raydir.y += self->plane.y * camera;
}
