/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:34:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 18:16:22 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "window.h"
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
	self->is_valid = TRUE;
	return (TRUE);
}

void	state_destroy(t_state *self)
{
	window_destroy(&self->window);
}

int	state_update(t_state *self)
{
	view_draw(&self->view, self->scene);
	return (0);
}