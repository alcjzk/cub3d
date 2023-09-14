/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:42:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/14 16:18:36 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <math.h>
# include "state.h"
# include "mouse_bonus.h"
# include "player.h"

void	player_update_yaw(t_player *self, t_state *state)
{
	int	mouse_dx;
	int	mouse_dy;

	if (state->is_mouse_captured)
	{
		mlx_get_mouse_pos(state->mlx, &mouse_dx, &mouse_dy);
		mouse_dx -= (state->mlx->width - 1) / 2;
		self->yaw += ((float)mouse_dx) * 0.1 * state->mlx->delta_time;
		mouse_align_center(state->mlx);
	}
	if (mlx_is_key_down(state->mlx, MLX_KEY_LEFT))
		self->yaw -= PLAYER_YAW_SPEED * state->mlx->delta_time;
	if (mlx_is_key_down(state->mlx, MLX_KEY_RIGHT))
		self->yaw += PLAYER_YAW_SPEED * state->mlx->delta_time;
	if (self->yaw < -M_PI)
		self->yaw += M_PI * 2;
	else if (self->yaw > M_PI)
		self->yaw -= M_PI * 2;
}

void	player_update(t_player *self, t_state *state)
{
	t_vec2f	velocity;
	t_map	*map;
	t_vec2f	position_new;

	map = &state->scene->map;
	player_update_yaw(self, state);
	self->direction = vec2f_rotate((t_vec2f){0.0, -1.0}, self->yaw);
	self->plane = vec2f_rotate((t_vec2f){0.66, 0.0}, self->yaw);
	velocity = player_velocity(self, state->mlx);
	position_new = vec2f_add(self->position, velocity);
	if (map->map[(int)self->position.y][(int)position_new.x] == '0')
		self->position.x = position_new.x;
	if (map->map[(int)position_new.y][(int)self->position.x] == '0')
		self->position.y = position_new.y;
}

#endif
