/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:16:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/17 14:08:06 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_BONUS_H
# define SCENE_BONUS_H

# include "bool.h"
# include "color.h"
# include "texture.h"
# include "map.h"

typedef struct s_player	t_player;
typedef BOOL			(*t_scene_config_func)(t_scene *, char *);

typedef struct s_scene
{
	t_texture_options	texture_options;
	t_texture_pack		textures;
	t_color				floor_color;
	t_color				ceiling_color;
	t_map				map;
	t_player			player;
	BOOL				is_floor_color_set;
	BOOL				is_ceiling_color_set;
	BOOL				is_valid;
}	t_scene;

typedef struct s_scene_config_map_item
{
	const char		*identifier;
	t_scene_config_func	func;
}	t_scene_config_map_item;

int		scene_create(t_scene *self, char *file);
void	scene_destroy(t_scene *self);
void	scene_print_error(t_scene *self);
BOOL	scene_read(int fd, char ***buffer);

//options
BOOL	scene_set_north(t_scene *self, char *line);
BOOL	scene_set_south(t_scene *self, char *line);
BOOL	scene_set_east(t_scene *self, char *line);
BOOL	scene_set_west(t_scene *self, char *line);
BOOL	scene_set_door(t_scene *self, char *line);
BOOL	scene_set_floor_color(t_scene *self, char *line);
BOOL	scene_set_ceiling_color(t_scene *self, char *line);
BOOL	scene_set_options(t_scene *self, char **buffer);

#endif
