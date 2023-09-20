/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 15:12:33 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"
#include "state.h"

_Bool	view_create(t_view *self, mlx_t *mlx)
{
	*self = (t_view){};
	self->mlx = mlx;
	if (!image_create(&self->frame, self->mlx, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (FALSE);
	sprite_create_test(&self->sprite);
	return (TRUE);
}

void	view_destroy(t_view *self)
{
	if (!self)
		return ;
	image_destroy(&self->frame);
	sprite_destroy(&self->sprite);
}
