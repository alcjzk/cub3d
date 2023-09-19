/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_textured_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:56:10 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 13:47:12 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <math.h>
# include "line_textured.h"
# include "libft.h"
# include "state.h"

float					texture_x(
							mlx_texture_t *self,
							t_ray *ray,
							t_player *player);

static mlx_texture_t	*texture_select(
		t_texture_pack *textures,
		t_scene *scene,
		t_side side,
		t_ray *ray)
{
	if (scene->map.map[(int)ray->map_pos.y][(int)ray->map_pos.x] == '2')
		return (scene->textures.door);
	else if (side == SIDE_NORTH)
		return (textures->north);
	else if (side == SIDE_EAST)
		return (textures->east);
	else if (side == SIDE_WEST)
		return (textures->west);
	else
		return (textures->south);
}

void	line_textured_init(
	t_line_textured *self,
	t_scene *scene,
	t_ray *ray)
{
	int	height;

	self->texture = texture_select(&scene->textures, scene, ray->side, ray);
	if (ray->perp_wall_dist == 0.0f)
		ray->perp_wall_dist = 0.1f;
	height = WINDOW_HEIGHT / ray->perp_wall_dist;
	self->start = -height / 2 + WINDOW_HEIGHT / 2;
	if (self->start < 0)
		self->start = 0;
	self->end = height / 2 + WINDOW_HEIGHT / 2;
	if (self->end >= WINDOW_HEIGHT)
		self->end = WINDOW_HEIGHT - 1;
	self->texture_x = texture_x(self->texture, ray, &scene->player);
	self->texture_step = 1.0 * (float)self->texture->height / (float)height;
	self->texture_y = (self->start - WINDOW_HEIGHT / 2 + height / 2)
		* self->texture_step;
}

#endif
