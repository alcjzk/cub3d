/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:13:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 16:50:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "bool.h"
# include "window.h"
# include "image.h"
# include "scene.h"

typedef struct s_view
{
	t_window	*window;
	t_image		frames[2];
	t_image		*front;
	t_image		*back;
}	t_view;

BOOL	view_create(t_view *self, t_window *window);
void	view_destroy(t_view *self);
void	view_swap_buffers(t_view *self);
void	view_draw(t_view *self, t_scene *scene);

#endif
