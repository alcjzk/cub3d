/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 21:04:15 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/11 18:48:06 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include <stdio.h>

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
				if (scene->start)
					return (FALSE);
				scene->start = map[y][x];
				scene->player_x = x;
				scene->player_y = y;
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
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
