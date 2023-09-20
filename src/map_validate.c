/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:38:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/20 14:50:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "player.h"
#include "map.h"

static _Bool	check_max_values(int y, int x, char **map)
{
	if (!map[y + 1] || y == 0 || x == 0)
	{
		if (map[y][x] == '1' || map[y][x] == ' ')
			return (TRUE);
		return (FALSE);
	}
	return (TRUE);
}

_Bool	map_validate_walls(t_map *self)
{
	int	x;
	int	y;

	if (!self->is_valid)
		return (FALSE);
	y = 0;
	while (self->map[y])
	{
		x = 0;
		while (self->map[y][x])
		{
			if (!check_max_values(y, x, self->map))
				return (FALSE);
			if (ft_strchr(INSIDE_CHARS, self->map[y][x]) &&
				(ft_strchr(" ", self->map[y - 1][x]) ||
				ft_strchr(" ", self->map[y + 1][x]) ||
				ft_strchr(" ", self->map[y][x - 1]) ||
				ft_strchr(" ", self->map[y][x + 1])))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

static void	revert_flood_fill(char **map, int map_char_len)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] != ' ')
				map[y][x] -= map_char_len;
			x++;
		}
		y++;
	}
}

static void	flood_fill(char **map, int y, int x, int map_char_len)
{
	if (map[y][x] && ft_strchr(MAP_CHARS, map[y][x]))
		map[y][x] += map_char_len;
	else
		return ;
	if (y != 0 && ft_strlen(map[y - 1]) >= (size_t)x)
		flood_fill(map, y - 1, x, map_char_len);
	if (map[y + 1] && ft_strlen(map[y + 1]) >= (size_t)x)
		flood_fill(map, y + 1, x, map_char_len);
	if (x != 0)
		flood_fill(map, y, x - 1, map_char_len);
	if (map[y][x + 1])
		flood_fill(map, y, x + 1, map_char_len);
}

_Bool	map_validate_islands(t_map *self, t_player *player)
{
	int	x;
	int	y;
	int	map_char_len;

	if (!self->is_valid)
		return (FALSE);
	map_char_len = ft_strlen(MAP_CHARS);
	flood_fill(self->map, player->position.y, player->position.x, map_char_len);
	y = 0;
	while (self->map[y])
	{
		x = 0;
		while (self->map[y][x])
		{
			if (ft_strchr(MAP_CHARS, self->map[y][x]))
				return (FALSE);
			x++;
		}
		y++;
	}
	revert_flood_fill(self->map, map_char_len);
	return (TRUE);
}
