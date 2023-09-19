/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:58:02 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/19 15:01:14 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "map.h"
# include "get_next_line.h"
# include <stdlib.h>
# include "libft.h"
# include "scene.h"

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

static BOOL	is_valid_map_char(char c)
{
	if (c == ' ')
		return (TRUE);
	if (ft_strchr(MAP_CHARS, c))
		return (TRUE);
	return (FALSE);
}

static BOOL	map_validate_symbols(t_map *self, t_player *player)
{
	int	x;
	int	y;

	y = 0;
	if (!self->is_valid)
		return (FALSE);
	while (self->map[y])
	{
		x = 0;
		while (self->map[y][x])
		{
			if (ft_strchr(PLAYER_CHARS, self->map[y][x]))
			{
				if (player->is_valid)
					return (FALSE);
				player_init(player, self->map[y][x], y, x);
				self->map[y][x] = '0';
			}
			else if (!is_valid_map_char(self->map[y][x]))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (player->is_valid);
}

BOOL	map_create(t_map *self, t_scene *scene, char **buffer)
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
	self->is_valid = map_validate_symbols(self, &scene->player);
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

#endif
