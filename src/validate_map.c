/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:04:15 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/12 13:08:46 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

char	*skip_empty(int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (line[i])
			break ;
		free(line);
		line = get_next_line(fd);
	}
	return (line);
}

void	init_player(t_scene *scene, char dir, int y, int x)
{
	scene->player.is_valid = TRUE;
	scene->player.position.x = x;
	scene->player.position.y = y;
	if (dir == 'N')
		scene->player.direction.y = 1;
	else if (dir == 'S')
		scene->player.direction.y = -1;
	else if (dir == 'W')
		scene->player.direction.x = -1;
	else if (dir == 'E')
		scene->player.direction.x = 1;
}

BOOL	check_symbols(t_scene *scene, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr(" 01NSWE", map[y][x]))
				return (FALSE);
			if (ft_strchr("NSWE", map[y][x]))
			{
				if (scene->player.is_valid)
					return (FALSE);
				init_player(scene, map[y][x], y, x);
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	if (!scene->player.is_valid)
		return (FALSE);
	return (TRUE);
}

BOOL	validate_map(t_scene *scene, int fd)
{
	char	*line;

	if (!scene->is_valid)
		return (FALSE);
	line = skip_empty(fd);
	scene->map = get_map(fd, line);
	if (!scene->map)
		return (FALSE);
	scene->is_valid = check_symbols(scene, scene->map);
	scene->is_valid = check_walls(scene, scene->map);
	scene->is_valid = check_connected(scene, scene->map);
	return (scene->is_valid);
}
