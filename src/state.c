/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:34:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/12 15:40:08 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "view.h"
#include "hook.h"
#include "state.h"

// TODO: Proper use of .is_valid
BOOL	state_create(t_state *self, t_scene *scene)
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
	if (!minimap_create(&self->minimap, scene, self->mlx))
		return (FALSE);
	self->scene = scene;
	self->is_valid = TRUE;
	return (TRUE);
}

void	state_destroy(t_state *self)
{
	scene_destroy(self->scene);
	mlx_terminate(self->mlx);
}

#ifndef BONUS_FEATURES

void	state_update(t_state *self)
{
	if (mlx_is_key_down(self->mlx, MLX_KEY_ESCAPE))
		return (on_close(self->mlx));
	player_update(&self->scene->player, self);
	view_draw(&self->view, self->scene);
	minimap_update(&self->minimap, self->scene);
}

#endif
