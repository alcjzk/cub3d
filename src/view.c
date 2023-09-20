/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:16:34 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 19:04:39 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"
#include "state.h"

#ifndef BONUS_FEATURES

_Bool	view_create(t_view *self, mlx_t *mlx)
{
	*self = (t_view){};
	self->mlx = mlx;
	if (!image_create(&self->frame, self->mlx, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (FALSE);
	return (TRUE);
}

#endif
