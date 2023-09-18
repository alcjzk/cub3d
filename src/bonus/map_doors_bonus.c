/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_doors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:49:30 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/18 17:00:50 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_bonus.h"
#include "libft.h"

static void	map_door_count(t_map *self)
{
	size_t	row;
	size_t	col;

	self->door_count = 0;
	row = 0;
	while (self->map[row])
	{
		col = 0;
		while (self->map[row][col])
		{
			if (self->map[row][col] == '2')
				self->door_count++;
			col++;
		}
		row++;
	}
}

static void	map_door_save_coords(t_map *self)
{
	size_t	row;
	size_t	col;
	size_t	door_i;

	row = 0;
	door_i = 0;
	while (self->map[row])
	{
		col = 0;
		while (self->map[row][col])
		{
			if (self->map[row][col] == '2')
			{
				self->doors[door_i].y = row;
				self->doors[door_i].x = col;
				door_i++;
			}
			col++;
		}
		row++;
	}

}

BOOL	map_door_save(t_map *self)
{
	if (!self->is_valid)
		return (FALSE);
	map_door_count(self);
	if (self->door_count == 0)
		return (TRUE);
	self->doors = ft_calloc(self->door_count, sizeof(t_door));
	if (!self->doors)
		return (FALSE);
	map_door_save_coords(self);
	return (TRUE);
}
