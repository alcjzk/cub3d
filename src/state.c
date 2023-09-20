/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:34:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 15:06:57 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "view.h"
#include "hook.h"
#include "state.h"

void	state_destroy(t_state *self)
{
	scene_destroy(self->scene);
	mlx_terminate(self->mlx);
}

#ifndef BONUS_FEATURES

// TODO: Proper use of .is_valid
_Bool	state_create(t_state *self, t_scene *scene)
{
	*self = (t_state){0};
	self->mlx = mlx_init(
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_TITLE,
			FALSE);
	if (!self->mlx)
		return (FALSE);
	if (!view_create(&self->view, self->mlx))
		return (FALSE);
	self->scene = scene;
	self->is_valid = TRUE;
	return (TRUE);
}

void	state_update(t_state *self)
{
	if (mlx_is_key_down(self->mlx, MLX_KEY_ESCAPE))
		return (on_close(self->mlx));
	player_update(&self->scene->player, self);
	view_draw(&self->view, self->scene);
}

#endif
