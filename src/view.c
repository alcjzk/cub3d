/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/12 15:50:00 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"
#include "state.h"

BOOL	view_create(t_view *self, mlx_t *mlx)
{
	*self = (t_view){};
	self->mlx = mlx;
	if (!image_create(&self->frame, self->mlx, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (FALSE);
	return (TRUE);
}

void	view_destroy(t_view *self)
{
	if (!self)
		return ;
	image_destroy(&self->frame);
}
