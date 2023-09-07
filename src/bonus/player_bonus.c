/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:42:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/07 18:54:34 by tjaasalo         ###   ########.fr       */
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

#endif
