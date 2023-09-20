/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:58:02 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/20 17:33:25 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "get_next_line.h"
#include <stdlib.h>
#include "libft.h"
#include "vec2i.h"
#include "scene.h"

_Bool	map_validate_symbols(
			t_map *self,
			t_player *player,
			t_scene *scene);

size_t	map_find_first_line(char **buffer)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (buffer[row])
	{
		col = 0;
		while (ft_isspace(buffer[row][col]))
			col++;
		if (buffer[row][col] && ft_strchr(MAP_CHARS, buffer[row][col]))
			return (row);
		row++;
	}
	return (0);
}

_Bool	is_valid_map_char(char c)
{
	if (c == ' ')
		return (TRUE);
	if (ft_strchr(MAP_CHARS, c))
		return (TRUE);
	return (FALSE);
}

#ifndef BONUS_FEATURES

_Bool	map_validate_symbols(
	t_map *self,
	t_player *player,
	t_scene *scene)
{
	t_vec2i	pos;

	(void)scene;
	pos.y = -1;
	if (!self->is_valid)
		return (FALSE);
	while (self->map[++(pos.y)])
	{
		pos.x = 0;
		while (self->map[pos.y][pos.x])
		{
			if (ft_strchr(PLAYER_CHARS, self->map[pos.y][pos.x]))
			{
				if (player->is_valid)
					return (FALSE);
				player_init(player, self->map[pos.y][pos.x], pos.y, pos.x);
				self->map[pos.y][pos.x] = '0';
			}
			else if (!is_valid_map_char(self->map[pos.y][pos.x]))
				return (FALSE);
			pos.x++;
		}
	}
	return (player->is_valid);
}

#endif

_Bool	map_create(t_map *self, t_scene *scene, char **buffer)
{
	size_t	first_map_line;

	if (!scene->is_valid)
		return (FALSE);
	*self = (t_map){0};
	self->is_valid = TRUE;
	first_map_line = map_find_first_line(buffer);
	if (!first_map_line)
		self->is_valid = FALSE;
	self->is_valid = map_read(self, &buffer[first_map_line]);
	self->is_valid = map_validate_symbols(self, &scene->player, scene);
	self->is_valid = map_validate_walls(self);
	self->is_valid = map_validate_islands(self, &scene->player);
	return (self->is_valid);
}

void	map_destroy(t_map *self)
{
	int	i;

	i = 0;
	if (self->map)
		while (self->map[i])
			free(self->map[i++]);
	free(self->map);
	*self = (t_map){0};
}
