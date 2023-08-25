/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:48:06 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/25 14:50:08 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include "bool.h"
#include <stdlib.h>
#include "player.h"

typedef struct s_scene	t_scene;

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	BOOL	is_valid;
}	t_map;

void	map_destroy(t_map *self);
BOOL	map_create(t_map *self, int fd, t_scene *scene);
BOOL	map_read(t_map *self, int fd, char *line);
BOOL	map_validate_islands(t_map *self, t_player *player);
BOOL	map_validate_walls(t_map *self);

#endif