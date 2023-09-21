/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_draw_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:13:02 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 16:57:55 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "state.h"
# include "sprite_bonus.h"
# include <stdlib.h>

static _Bool	is_visible(int x, float z, float *z_buffer);
t_color			color_add_shadow(t_color color, float amount);

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

static _Bool	is_visible(int x, float z, float *z_buffer)
{
	if (x < 0 || x >= WINDOW_WIDTH)
		return (FALSE);
	if (z < 0 || z > z_buffer[x])
		return (FALSE);
	return (TRUE);
}

#endif
