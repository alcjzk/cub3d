/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:16:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 17:28:20 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_BONUS_H
# define SCENE_BONUS_H

# include "color.h"
# include "texture.h"
# include "vector.h"
# include "sprite_bonus.h"
# include "map.h"

# define CONFIG_FUNC_COUNT 8

typedef struct s_player	t_player;
typedef _Bool			(*t_scene_config_func)(t_scene *, char *);

typedef struct s_scene
{
	t_texture_options	texture_options;
	t_texture_pack		textures;
	t_color				floor_color;
	t_color				ceiling_color;
	t_map				map;
	t_player			player;
	_Bool				is_floor_color_set;
	_Bool				is_ceiling_color_set;
	t_vector			*sprites;
	t_sprite			**sprites_sorted;
	_Bool				is_valid;
}	t_scene;

typedef struct s_scene_config_map_item
{
	const char			*identifier;
	t_scene_config_func	func;
}	t_scene_config_map_item;

_Bool					scene_create(t_scene *self, const char *config_path);
void					scene_destroy(t_scene *self);
_Bool					scene_read(int fd, char ***buffer);

//options
_Bool					scene_set_north(t_scene *self, char *line);
_Bool					scene_set_south(t_scene *self, char *line);
_Bool					scene_set_east(t_scene *self, char *line);
_Bool					scene_set_west(t_scene *self, char *line);
_Bool					scene_set_sprite(t_scene *self, char *line);
_Bool					scene_set_door(t_scene *self, char *line);
_Bool					scene_set_floor_color(t_scene *self, char *line);
_Bool					scene_set_ceiling_color(t_scene *self, char *line);
_Bool					scene_set_options(t_scene *self, char **buffer);

_Bool					scene_is_colors_set(t_scene *self);
t_scene_config_map_item	*scene_config_map(void);

_Bool					scene_add_sprite(t_scene *self, t_vec2i position);
_Bool					scene_init_sprites(t_scene *self);
void					scene_free_sprites(t_scene *self);
void					scene_sort_sprites(t_scene *self);

#endif
