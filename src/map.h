/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:48:06 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/31 16:06:36 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <stdlib.h>
#include "bool.h"

typedef struct s_scene	t_scene;
typedef struct s_player	t_player;

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