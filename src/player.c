/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:07:59 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/31 19:25:55 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "player.h"
#include "util.h"
#include "state.h"

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

t_vec2f	player_velocity(t_player *self, mlx_t *mlx)
{
	t_vec2f	velocity;
	t_vec2f	direction;

	direction = (t_vec2f){0};
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		direction.y -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		direction.y += 1;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		direction.x -= 1;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		direction.x += 1;
	direction = vec2f_normalize(direction);
	velocity = vec2f_mul(direction, PLAYER_MOVE_SPEED * mlx->delta_time);
	velocity = vec2f_rotate(velocity, self->yaw);
	return (velocity);
}

void	player_update_yaw(t_player *self, mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		self->yaw -= PLAYER_YAW_SPEED * mlx->delta_time;
		if (self->yaw < -M_PI)
			self->yaw += M_PI * 2;
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		self->yaw += PLAYER_YAW_SPEED * mlx->delta_time;
		if (self->yaw > M_PI)
			self->yaw -= M_PI * 2;
	}
}

void	player_update(t_player *self, mlx_t *mlx, t_map *map)
{
	t_vec2f	velocity;

	player_update_yaw(self, mlx);
	velocity = player_velocity(self, mlx);
	self->direction = vec2f_rotate((t_vec2f){0.0, -1.0}, self->yaw);
	self->plane = vec2f_rotate((t_vec2f){0.66, 0.0}, self->yaw);
	self->position = vec2f_add(self->position, velocity);
	self->position.x = clampf(self->position.x, 0.5f, map->width - 0.5f);
	self->position.y = clampf(self->position.y, 0.5f, map->height - 0.5f);
}
