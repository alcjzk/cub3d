/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:24:08 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/31 16:16:33 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "scene.h"
# include "image.h"

# define BLOCK_SIZE 8
# define BORDER_OFFSET 2
# define BORDER 0xFF0000FF
# define BACKGROUND 0xFFFF0000
# define WALL 0xFF000000
# define PLAYER 0xFF0000FF

typedef struct s_minimap
{
	size_t	width;
	size_t	height;
	t_image	img;
} t_minimap;

BOOL	minimap_create(t_minimap *self, t_scene *scene, mlx_t *mlx);
void	minimap_update(t_minimap *self, t_scene *scene, t_player *player);

#endif