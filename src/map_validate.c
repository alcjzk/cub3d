/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:38:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/31 16:06:49 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "player.h"
#include "map.h"

static BOOL	check_wall_is_zero(int y, int x, char **map)
{
	if (map[y][x] == '0')
	{
		if (!map[y + 1])
			return (TRUE);
		else if (y == 0)
			return (TRUE);
		else if (x == 0)
			return (TRUE);
		else if (ft_strlen(map[y + 1]) < (size_t)x + 1)
			return (TRUE);
		else if (ft_strlen(map[y - 1]) < (size_t)x + 1)
			return (TRUE);
	}
	return (FALSE);
}

BOOL	map_validate_walls(t_map *self)
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
			if (check_wall_is_zero(y, x, self->map))
				return (FALSE);
			if (self->map[y][x] == '0' &&
				(!ft_strchr("01", self->map[y - 1][x]) ||
				!ft_strchr("01", self->map[y + 1][x]) ||
				!ft_strchr("01", self->map[y][x - 1]) ||
				!ft_strchr("01", self->map[y][x + 1])))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

static void	change_chars(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
				map[y][x] = '0';
			else if (map[y][x] == '3')
				map[y][x] = '1';
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == '0')
		map[y][x] += 2;
	else
		return ;
	if (y != 0 && ft_strlen(map[y - 1]) >= (size_t)x)
		flood_fill(map, y - 1, x);
	if (map[y + 1] && ft_strlen(map[y + 1]) >= (size_t)x)
		flood_fill(map, y + 1, x);
	if (x != 0)
		flood_fill(map, y, x - 1);
	if (map[y][x + 1])
		flood_fill(map, y, x + 1);
}

BOOL	map_validate_islands(t_map *self, t_player *player)
{
	int	x;
	int	y;

	if (!self->is_valid)
		return (FALSE);
	flood_fill(self->map, player->position.y, player->position.x);
	y = 0;
	while (self->map[y])
	{
		x = 0;
		while (self->map[y][x])
		{
			if (self->map[y][x] == '0' || self->map[y][x] == '1')
				return (FALSE);
			x++;
		}
		y++;
	}
	change_chars(self->map);
	return (TRUE);
}
