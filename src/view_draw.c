/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:03 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 17:06:17 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "view.h"

void	view_draw(t_view *self, t_scene *scene)
{
	(void)scene;
	// Draw full background or clear view->back
	// Draw world
	view_swap_buffers(self);
}
