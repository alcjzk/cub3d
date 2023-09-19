/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:34:04 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/19 17:17:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "vector.h"
#include "get_next_line.h"
#include "libft.h"

void	map_get_max_size(t_map *self, char **map)
{
	size_t	col;
	size_t	row;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
			col++;
		if (col > self->width)
			self->width = col;
		row++;
	}
	self->height = row;
}

_Bool	map_allocate(t_map *self)
{
	size_t	row;

	self->map = ft_calloc(self->height + 1, sizeof(char *));
	if (!self->map)
		return (FALSE);
	row = 0;
	while (row < self->height)
	{
		self->map[row] = ft_calloc(self->width + 1, sizeof(char));
		if (!self->map[row])
		{
			while (row--)
				free(self->map[row]);
			free(self->map);
			self->map = NULL;
			return (FALSE);
		}
		row++;
	}
	return (TRUE);
}

void	map_copy(t_map *self, char **map)
{
	size_t	row;
	size_t	col;

	if (!self->is_valid)
		return ;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			self->map[row][col] = map[row][col];
			col++;
		}
		row++;
	}
}

_Bool	map_read(t_map *self, char **map)
{
	if (!self->is_valid)
		return (FALSE);
	map_get_max_size(self, map);
	self->is_valid = map_allocate(self);
	map_copy(self, map);
	return (TRUE);
}
