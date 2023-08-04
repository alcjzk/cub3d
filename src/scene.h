/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:16:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/04 16:58:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "bool.h"
# include "color.h"
# include "player.h"
# include "map.h"

typedef struct s_scene
{
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
	t_color		floor_color;
	BOOL		set_floor_color;
	t_color		ceiling_color;
	BOOL		set_ceiling_color;
	t_map		map;
	t_player	player;
	BOOL		is_valid;
}	t_scene;

int		scene_create(t_scene *scene, char *file);
int		get_color(t_scene *scene, char *line);
BOOL	get_elements(t_scene *scene, int fd);
void	scene_destroy(t_scene *scene);

#endif
