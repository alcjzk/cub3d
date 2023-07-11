/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/05 16:03:34 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "view.h"

BOOL	view_create(t_view *self, t_window *window)
{
	*self = (t_view){0};
	self->window = window;
	self->front = &self->frames[0];
	self->back = &self->frames[1];
	if (!image_create(self->front, window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (FALSE);
	if (!image_create(self->back, window->mlx, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (FALSE);
	return (TRUE);
}

void	view_destroy(t_view *self)
{
	if (!self)
		return ;
	image_destroy(self->front);
	image_destroy(self->back);
}

void	view_swap_buffers(t_view *self)
{
	t_image	*tmp;

	tmp = self->front;
	self->front = self->back;
	self->back = tmp;
}
