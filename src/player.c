/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:07:59 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/25 13:04:22 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "player.h"
#include "window.h"

void	player_init(t_player *self, char dir, int y, int x)
{
	*self = (t_player){{0}, {0}, {0}, {0}, 0.0, TRUE};
	self->position.x = x + 0.5f;
	self->position.y = y + 0.5f;
	if (dir == 'S')
		self->yaw = M_PI;
	else if (dir == 'W')
		self->yaw = -M_PI_2;
	else if (dir == 'E')
		self->yaw = M_PI_2;
}

void	player_raydir_calc(t_player *self, int x)
{
	float	camera;

	camera = 2.0 * x / (float)WINDOW_WIDTH - 1.0;
	self->raydir.x = self->direction.x;
	self->raydir.x += self->plane.x * camera;
	self->raydir.y = self->direction.y;
	self->raydir.y += self->plane.y * camera;
}

t_vec2f	player_velocity(t_player *self, t_keymap *keymap)
{
	t_vec2f	velocity;
	t_vec2f	direction;

	direction = (t_vec2f){0};
	if (keymap_key_state(keymap, KEY_W) == KEY_STATE_DOWN)
		direction.y -= 1;
	if (keymap_key_state(keymap, KEY_S) == KEY_STATE_DOWN)
		direction.y += 1;
	if (keymap_key_state(keymap, KEY_A) == KEY_STATE_DOWN)
		direction.x -= 1;
	if (keymap_key_state(keymap, KEY_D) == KEY_STATE_DOWN)
		direction.x += 1;
	direction = vec2f_normalize(direction);
	velocity = vec2f_mul(direction, PLAYER_MOVE_SPEED);
	velocity = vec2f_rotate(velocity, self->yaw);
	return (velocity);
}

void	player_update_yaw(t_player *self, t_keymap *keymap)
{
	if (keymap_key_state(keymap, KEY_LEFT) == KEY_STATE_DOWN)
	{
		self->yaw -= PLAYER_YAW_SPEED;
		if (self->yaw < -M_PI)
			self->yaw += M_PI * 2;
	}
	if (keymap_key_state(keymap, KEY_RIGHT) == KEY_STATE_DOWN)
	{
		self->yaw += PLAYER_YAW_SPEED;
		if (self->yaw > M_PI)
			self->yaw -= M_PI * 2;
	}
}

void	player_update(t_player *self, t_keymap *keymap)
{
	t_vec2f	velocity;

	player_update_yaw(self, keymap);
	velocity = player_velocity(self, keymap);
	self->direction = vec2f_rotate((t_vec2f){0.0, -1.0}, self->yaw);
	self->plane = vec2f_rotate((t_vec2f){0.66, 0.0}, self->yaw);
	self->position = vec2f_add(self->position, velocity);
}
