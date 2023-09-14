/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:19:31 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/14 15:45:11 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "mouse_bonus.h" 
#include "state_bonus.h"

void	state_update(t_state *self)
{
	if (mlx_is_key_down(self->mlx, MLX_KEY_ESCAPE))
		return (on_close(self->mlx));
	if (mlx_is_mouse_down(self->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		if (!self->is_mouse_captured)
			self->is_mouse_captured = mouse_try_capture(self->mlx);
	}
	else if (mlx_is_mouse_down(self->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		if (self->is_mouse_captured)
		{
			mouse_release(self->mlx);
			self->is_mouse_captured = FALSE;
		}
	}
	player_update(&self->scene->player, self);
	view_draw(&self->view, self->scene);
}
