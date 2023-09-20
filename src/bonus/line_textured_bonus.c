/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_textured_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:56:10 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 14:04:43 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <math.h>
# include "line_textured.h"
# include "libft.h"
# include "state.h"

t_color	color_add_shadow(t_color color, float amount);
t_color	texture_pixel(mlx_texture_t *texture, int x, int y);
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

void	line_textured_draw(t_line_textured *self, t_view *view, int x)
{
	int		screen_y;
	t_color	color;

	screen_y = self->start;
	while (screen_y <= self->end)
	{
		if (self->texture_y >= (float)self->texture->height)
			self->texture_y = (float)self->texture->height - 1;
		color = texture_pixel(
				self->texture,
				self->texture_x,
				(int)self->texture_y);
		color = color_add_shadow(
				color,
				(float)(self->end - self->start) / (float)view->frame.height);
		image_put_pixel(&view->frame, x, screen_y, color);
		self->texture_y += self->texture_step;
		screen_y++;
	}
}

#endif
