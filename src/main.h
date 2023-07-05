/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:09 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/05 14:11:24 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "bool.h"
# include "vector.h"
# include "libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "color.h"

typedef struct s_scene
{
	char	*north_texture_path;
	char	*south_texture_path;
	char	*west_texture_path;
	char	*east_texture_path;
	t_color	floor_color;
	t_color	ceiling_color;
	char	**map;
	int		player_x;
	int		player_y;
	char	start;
	BOOL	is_valid;
}	t_scene;

int	validate(t_scene *scene, char *file);

#endif