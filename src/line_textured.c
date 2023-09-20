/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_textured.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:56:10 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 12:54:12 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "line_textured.h"
#include "libft.h"
#include "state.h"

static t_color	texture_pixel(mlx_texture_t *texture, int x, int y);
float			texture_x(
					mlx_texture_t *self,
					t_ray *ray,
					t_player *player);
mlx_texture_t	*texture_select(
					t_texture_pack *textures,
					t_scene *scene,
					t_ray *ray);

#ifndef BONUS_FEATURES

mlx_texture_t	*texture_select(
		t_texture_pack *textures,
		t_scene *scene,
		t_ray *ray)
{
	(void)scene;
	if (ray->side == SIDE_NORTH)
		return (textures->north);
	else if (ray->side == SIDE_EAST)
		return (textures->east);
	else if (ray->side == SIDE_WEST)
		return (textures->west);
	else
		return (textures->south);
}

#endif

void	line_textured_init(
	t_line_textured *self,
	t_scene *scene,
	t_ray *ray)
{
	int	height;

	self->texture = texture_select(&scene->textures, scene, ray);
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

static t_color	texture_pixel(mlx_texture_t *texture, int x, int y)
{
	return (((t_color *)texture->pixels)[y * texture->width + x]);
}

float	texture_x(mlx_texture_t *self, t_ray *ray, t_player *player)
{
	float	texture_x;

	if (ray->side == SIDE_EAST || ray->side == SIDE_WEST)
		texture_x = player->position.y + ray->perp_wall_dist * player->raydir.y;
	else
		texture_x = player->position.x + ray->perp_wall_dist * player->raydir.x;
	texture_x -= floor(texture_x);
	texture_x *= (float)self->width;
	if ((ray->side == SIDE_EAST) || (ray->side == SIDE_NORTH))
		texture_x = (float)self->width - texture_x - 1;
	return (texture_x);
}
