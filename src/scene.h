/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:16:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/03 16:08:41 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"
# include "bool.h"
# include "vector.h"
# include "libft.h"
# include "color.h"
# include "player.h"

typedef struct s_scene
{
	char		*north_texture_path;
	char		*south_texture_path;
	char		*west_texture_path;
	char		*east_texture_path;
	t_color		floor_color;
	t_color		ceiling_color;
	char		**map;
	t_player	player;
	BOOL		is_valid;
}	t_scene;

int		validate(t_scene *scene, char *file);
int		get_color(t_scene *scene, char *line);
BOOL	get_elements(t_scene *scene, int fd);
char	**get_map(int fd, char *line);
BOOL	check_connected(t_scene *scene, char **map);
BOOL	check_walls(t_scene *scene, char **map);
BOOL	validate_map(t_scene *scene, int fd);
void	scene_destroy(t_scene *scene);

#endif
