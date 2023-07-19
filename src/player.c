/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:07:59 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/19 14:18:52 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

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
