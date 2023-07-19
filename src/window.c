/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 13:51:33 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 15:35:39 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "window.h"

t_window	*window_create(
	t_window *self,
	void *mlx)
{
	*self = (t_window){0};
	self->window = mlx_new_window(
			mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			WINDOW_TITLE);
	if (!self->window)
		return (NULL);
	self->mlx = mlx;
	return (self);
}

void	window_destroy(t_window *self)
{
	if (self->window)
		mlx_destroy_window(self->mlx, self->window);
	*self = (t_window){0};
}
