/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:34:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 16:47:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "view.h"
#include "scene.h"
#include "state.h"

#ifndef BONUS_FEATURES

static void	on_close(mlx_t *mlx)
{
	mlx_close_window(mlx);
}

void	state_destroy(t_state *self)
{
	scene_destroy(&self->scene);
	if (self->mlx)
		mlx_terminate(self->mlx);
}

_Bool	state_create(t_state *self, const char *config_path)
{
	*self = (t_state){0};
	if (!scene_create(&self->scene, config_path))
		return (FALSE);
	self->mlx = mlx_init(
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_TITLE,
			FALSE);
	if (!self->mlx)
		return (FALSE);
	if (!view_create(&self->view, self->mlx))
		return (FALSE);
	if (mlx_image_to_window(self->mlx, self->view.frame.img, 0, 0) == -1)
		return (FALSE);
	mlx_close_hook(self->mlx, (mlx_closefunc)on_close, self->mlx);
	if (!mlx_loop_hook(self->mlx, (void (*)(void *))state_update, self))
		return (FALSE);
	return (TRUE);
}

void	state_update(t_state *self)
{
	if (mlx_is_key_down(self->mlx, MLX_KEY_ESCAPE))
		return (on_close(self->mlx));
	player_update(&self->scene.player, self);
	view_draw(&self->view, &self->scene);
}

#endif
