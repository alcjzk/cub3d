/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:38:51 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/05 20:57:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

BOOL	check_wall_is_zero(int y, int x, char **map)
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

BOOL	check_walls(t_scene *scene, char **map)
{
	int	x;
	int	y;

	if (!scene->is_valid)
		return (FALSE);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_wall_is_zero(y, x, map))
				return (FALSE);
			if (map[y][x] == '0' &&
				(!ft_strchr("01", map[y - 1][x]) ||
				!ft_strchr("01", map[y + 1][x]) ||
				!ft_strchr("01", map[y][x - 1]) ||
				!ft_strchr("01", map[y][x + 1])))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

void	change_chars(char **map)
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

BOOL	check_connected(t_scene *scene, char **map)
{
	int	x;
	int	y;

	if (!scene->is_valid)
		return (FALSE);
	flood_fill(map, scene->player_y, scene->player_x);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == '1')
				return (FALSE);
			x++;
		}
		y++;
	}
	change_chars(map);
	return (TRUE);
}
