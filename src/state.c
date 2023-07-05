/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:34:14 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/04 17:48:30 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "window.h"
#include "state.h"

BOOL	state_create(t_state *self, void *mlx)
{
	*self = (t_state){0};
	if (!window_create(&self->window, mlx))
		return (FALSE);
	self->mlx = mlx;
	self->is_valid = TRUE;
	return (TRUE);
}

void	state_destroy(t_state *self)
{
	window_destroy(&self->window);
}
