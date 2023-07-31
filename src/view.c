/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/31 18:31:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"
#include "state.h"

BOOL	view_create(t_view *self, mlx_t *mlx)
{
	*self = (t_view){};
	self->mlx = mlx;
	self->front = &self->frames[0];
	self->back = &self->frames[1];
	if (!image_create(self->front, self->mlx, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (FALSE);
	if (!image_create(self->back, self->mlx, WINDOW_WIDTH, WINDOW_HEIGHT))
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
