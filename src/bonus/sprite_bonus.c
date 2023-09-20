/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:56:58 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 18:48:03 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "state.h"
#include "map.h"
#include "sprite_bonus.h"
#include <math.h>

// TODO: Feature flag

t_color	color_add_shadow(t_color color, float amount);

void	sprite_create_test(t_sprite *self)
{
	*self = (t_sprite){};
	self->position = (t_vec2f){2.0f, 2.0f};
	self->texture = mlx_load_png("./textures/sprite.png");
}

void	sprite_destroy(t_sprite *self)
{
	mlx_delete_texture(self->texture);
	*self = (t_sprite){};
}

t_vec2f	sprite_transform(t_sprite *self, t_player *player)
{
	double	inverse_determinant;
	t_vec2f	transform;
	t_vec2f	sprite_position;

	sprite_position = vec2f_sub(self->position, player->position);
	inverse_determinant = 1.0 / (player->plane.x
			* player->direction.y
			- player->direction.x 
			* player->plane.y);
	transform.x = inverse_determinant * (player->direction.y
			* sprite_position.x
			- player->direction.x
			* sprite_position.y);
	transform.y = inverse_determinant * (-player->plane.y
			* sprite_position.x
			+ player->plane.x
			* sprite_position.y);
	return (transform);
}

void	sprite_draw_init(
	t_sprite_draw *self,
	t_sprite *sprite,
	t_player *player)
{
	double	time;

	self->transform = sprite_transform(sprite, player);
	self->sprite_screen_x = (WINDOW_WIDTH / 2)
		* (1 + self->transform.x / self->transform.y);
	self->sprite_height = abs((int)(WINDOW_HEIGHT / self->transform.y))
		* SPRITE_SCALE;
	self->start.y = -self->sprite_height / 2 + WINDOW_HEIGHT / 2;
	if (self->start.y < 0)
		self->start.y = 0;
	self->end.y = self->sprite_height / 2 + WINDOW_HEIGHT / 2;
	if (self->end.y >= WINDOW_HEIGHT)
		self->end.y = WINDOW_HEIGHT - 1;
	self->start.x = -self->sprite_height / 2 + self->sprite_screen_x;
	if (self->start.x < 0)
		self->start.x = 0;
	self->end.x = self->sprite_height / 2 + self->sprite_screen_x;
	if (self->end.x >= WINDOW_WIDTH)
		self->end.x = WINDOW_WIDTH - 1;
	self->sprite_frames = sprite->texture->width / sprite->texture->height;
	self->sprite = sprite;
	time = mlx_get_time();
	time -= (int)time;
	self->frame_offset = ((int)(self->sprite_frames * time))
		* self->sprite->texture->height;
}

static _Bool	is_visible(int x, float z, float *z_buffer)
{
	if (x < 0 || x >= WINDOW_WIDTH)
		return (FALSE);
	if (z < 0 || z > z_buffer[x])
		return (FALSE);
	return (TRUE);
}

void	sprite_draw_line(
	t_sprite_draw *self,
	t_image *image,
	int x)
{
	int		y;
	t_color	pixel;

	y = self->start.y;
	while (y < self->end.y)
	{
		self->texpos.y
			= (y - WINDOW_HEIGHT / 2 + self->sprite_height / 2)
			* self->sprite->texture->height / self->sprite_height;
		pixel = ((t_color *)self->sprite->texture->pixels)[
			self->sprite->texture->width
			* self->texpos.y + self->texpos.x
		];
		pixel = color_add_shadow(
			pixel,
			(float)(self->end.y - self->start.y) / WINDOW_HEIGHT);
		if (pixel.channels.a > 0)
			image_put_pixel(image, x, y, pixel);
		y++;
	}
}

void	sprite_draw_draw(t_sprite_draw *self, float *z_buffer, t_image *image)
{
	int		x;

	x = self->start.x;
	while (x < self->end.x)
	{
		self->texpos.x = ((x - (-self->sprite_height / 2
						+ self->sprite_screen_x))
				* self->sprite->texture->height / self->sprite_height);
		self->texpos.x += self->frame_offset;
		if (is_visible(x, self->transform.y, z_buffer))
			sprite_draw_line(self, image, x);
		x++;
	}
}

void	sprite_update_distance_to_player(t_sprite *self, t_player *player)
{
	self->distance_to_player
		= (player->position.x - self->position.x)
		* (player->position.x - self->position.x)
		+ (player->position.y - self->position.y)
		* (player->position.y - self->position.y);
}
