/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:48:06 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/14 15:22:59 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include <stdlib.h>
# include "bool.h"
# include "player.h"

# define MAP_CHARS		"012"
# define PLAYER_CHARS	"NSWE"
# define INSIDE_CHARS	"02"

typedef struct s_scene	t_scene;

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	BOOL	is_valid;
}	t_map;

void	map_destroy(t_map *self);
BOOL	map_create(t_map *self, t_scene *scene, char **buffer);
BOOL	map_read(t_map *self, char **map);
BOOL	map_validate_islands(t_map *self, t_player *player);
BOOL	map_validate_walls(t_map *self);

#endif
