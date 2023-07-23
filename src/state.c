/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:34:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/23 15:48:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "window.h"
#include "player.h"
#include "view.h"
#include "state.h"

// TODO: Proper use of .is_valid
BOOL	state_create(t_state *self, void *mlx, t_scene *scene)
{
	*self = (t_state){0};
	if (!window_create(&self->window, mlx))
		return (FALSE);
	if (!view_create(&self->view, &self->window))
		return (FALSE);
	self->mlx = mlx;
	self->scene = scene;
	self->keymap = (t_keymap){{0}};
	self->is_valid = TRUE;
	return (TRUE);
}

void	state_destroy(t_state *self)
{
	window_destroy(&self->window);
}

int	state_update(t_state *self)
{
	player_update(&self->scene->player, &self->keymap);
	view_draw(&self->view, self->scene);
	return (0);
}
