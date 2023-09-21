/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:19:31 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 15:26:30 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "hook.h"
# include "mouse_bonus.h" 
# include "state_bonus.h"

void	state_destroy(t_state *self)
{
	view_destroy(&self->view);
	scene_destroy(self->scene);
	mlx_terminate(self->mlx);
}

_Bool	state_create(t_state *self, const char *config_path)
{
	*self = (t_state){0};
	self->scene = &self->scene_real;
	if (!scene_create(&self->scene_real, config_path))
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
	if (!minimap_create(&self->minimap, self->scene, self->mlx))
		return (FALSE);
	if (mlx_image_to_window(self->mlx, self->view.frame.img, 0, 0) == -1)
		return (FALSE);
	mlx_close_hook(self->mlx, (mlx_closefunc)on_close, self->mlx);
	mlx_key_hook(self->mlx, (mlx_keyfunc)map_door_toggle, self->scene);
	if (!mlx_loop_hook(self->mlx, (void (*)(void *))state_update, self))
		return (FALSE);
	return (TRUE);
}

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
	minimap_update(&self->minimap, self->scene);
}

#endif
