/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:48:06 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 16:57:12 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_BONUS_H
# define MAP_BONUS_H

# include "player.h"

# define MAP_CHARS		"0124"
# define PLAYER_CHARS	"NSWE"
# define INSIDE_CHARS	"024"

typedef struct s_scene	t_scene;

typedef struct s_map
{
	char	**map;
	size_t	width;
	size_t	height;
	_Bool	is_valid;
}	t_map;

void	map_destroy(t_map *self);
_Bool	map_create(t_map *self, t_scene *scene, char **buffer);
_Bool	map_read(t_map *self, char **map);
_Bool	map_validate_islands(t_map *self, t_player *player);
_Bool	map_validate_walls(t_map *self);
size_t	map_find_first_line(char **buffer);
void	map_door_toggle(mlx_key_data_t keydata, t_scene *scene);

#endif
