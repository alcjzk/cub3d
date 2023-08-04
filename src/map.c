/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:58:02 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/04 17:12:41 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "get_next_line.h"
#include <stdlib.h>
#include "libft.h"
#include "scene.h"

static char	*skip_empty_lines(int fd)
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

static BOOL	validate_symbols(char **map, t_scene *scene)
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
				player_init(&scene->player, map[y][x], y, x);
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (scene->player.is_valid);
}

BOOL	map_create(t_map *self, int fd, t_scene *scene)
{
	char	*line;

	if (!scene->is_valid)
		return (FALSE);
	self = (t_map *){0};
	line = skip_empty_lines(fd);
	self->is_valid = map_read(self, fd, line);
	self->is_valid = validate_symbols(self->map, scene);
	self->is_valid = map_validate_walls(self);
	self->is_valid = map_validate_islands(self, scene);
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
}