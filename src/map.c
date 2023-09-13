/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:58:02 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/13 23:24:51 by tjaasalo         ###   ########.fr       */
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

static BOOL	validate_symbols(t_map *self, t_player *player)
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
			if (!ft_strchr(" 01NSWE", self->map[y][x]))
				return (FALSE);
			if (ft_strchr("NSWE", self->map[y][x]))
			{
				if (player->is_valid)
					return (FALSE);
				player_init(player, self->map[y][x], y, x);
				self->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (player->is_valid);
}

BOOL	map_create(t_map *self, int fd, t_scene *scene)
{
	char	*line;

	if (!scene->is_valid)
		return (FALSE);
	*self = (t_map){0};
	self->is_valid = TRUE;
	line = skip_empty_lines(fd);
	self->is_valid = map_read(self, fd, line);
	self->is_valid = validate_symbols(self, &scene->player);
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
}
