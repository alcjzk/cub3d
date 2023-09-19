/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:16:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/19 17:17:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# ifdef BONUS_FEATURES
#  include "scene_bonus.h"
# else

#  include "bool.h"
#  include "color.h"
#  include "texture.h"
#  include "map.h"

#  define CONFIG_FUNC_COUNT 6

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
	_Bool				is_valid;
}	t_scene;

typedef struct s_scene_config_map_item
{
	const char			*identifier;
	t_scene_config_func	func;
}	t_scene_config_map_item;

int						scene_create(t_scene *self, char *file);
void					scene_destroy(t_scene *self);
void					scene_print_error(t_scene *self);
_Bool					scene_read(int fd, char ***buffer);

//options
_Bool					scene_set_north(t_scene *self, char *line);
_Bool					scene_set_south(t_scene *self, char *line);
_Bool					scene_set_east(t_scene *self, char *line);
_Bool					scene_set_west(t_scene *self, char *line);
_Bool					scene_set_floor_color(t_scene *self, char *line);
_Bool					scene_set_ceiling_color(t_scene *self, char *line);
_Bool					scene_set_options(t_scene *self, char **buffer);
t_scene_config_map_item	*scene_config_map(void);

# endif
#endif
