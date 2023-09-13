/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:16:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/13 17:24:38 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "bool.h"
# include "color.h"
# include "texture.h"
# include "map.h"
# include <stdio.h>

typedef struct s_player	t_player;
typedef	BOOL	(*func)(t_scene *, char *);

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

int		scene_create(t_scene *self, char *file);
int		get_color(t_scene *scene, char *line);
BOOL	get_elements(t_scene *scene, int fd);
void	scene_destroy(t_scene *self);
void	scene_print_error(t_scene *self);
int		validate_name(char *file);
BOOL	scene_set_north(t_scene *self, char *line);
BOOL	scene_set_south(t_scene *self, char *line);
BOOL	scene_set_east(t_scene *self, char *line);
BOOL	scene_set_west(t_scene *self, char *line);
BOOL	scene_set_door(t_scene *self, char *line);
BOOL	scene_set_floor_color(t_scene *self, char *line);
BOOL	scene_set_ceiling_color(t_scene *self, char *line);

#endif
