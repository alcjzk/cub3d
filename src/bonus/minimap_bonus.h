/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:24:08 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/20 15:00:32 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "scene.h"
# include "image.h"

# define BLOCK_SIZE		16
# define BORDER_OFFSET	3
# define BORDER			0xFF6A61BF
# define BACKGROUND		0xFF6A564C
# define WALL			0xFF40342E
# define PLAYER			0xFF8CBEA3
# define DOOR			0xFF7087D0

typedef struct s_minimap
{
	size_t	width;
	size_t	height;
	t_image	img;
}	t_minimap;

_Bool	minimap_create(t_minimap *self, t_scene *scene, mlx_t *mlx);
void	minimap_update(t_minimap *self, t_scene *scene);
void	minimap_wall_draw(t_minimap *self, t_scene *scene);

#endif