/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:34:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/08/31 16:26:55 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "view.h"
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
	self->keymap = (t_keymap){{0}};
	self->is_valid = TRUE;
	return (TRUE);
}

void	state_destroy(t_state *self)
{
	scene_destroy(self->scene);
	mlx_terminate(self->mlx);
}

void	state_update(t_state *self)
{
	player_update(&self->scene->player, &self->keymap);
	view_draw(&self->view, self->scene);
	minimap_update(&self->minimap, self->scene, &self->scene->player);
}
