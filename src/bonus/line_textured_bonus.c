/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_textured_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:56:10 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 16:42:41 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <math.h>
# include "line_textured.h"
# include "libft.h"
# include "state.h"

float	texture_x(
			mlx_texture_t *self,
			t_ray *ray,
			t_player *player);

mlx_texture_t	*texture_select(
	t_texture_pack *textures,
	t_scene *scene,
	t_ray *ray)
{
	if (scene->map.map[(int)ray->map_pos.y][(int)ray->map_pos.x] == '2')
		return (scene->textures.door);
	else if (ray->side == SIDE_NORTH)
		return (textures->north);
	else if (ray->side == SIDE_EAST)
		return (textures->east);
	else if (ray->side == SIDE_WEST)
		return (textures->west);
	else
		return (textures->south);
}

#endif
