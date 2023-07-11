/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:05:27 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 17:32:50 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <mlx.h>
# include "bool.h"
# include "window.h"
# include "view.h"
# include "scene.h"

typedef struct s_state
{
	void		*mlx;
	t_window	window;
	t_view		view;
	t_scene		*scene;
	BOOL		is_valid;
}	t_state;

BOOL	state_create(t_state *self, void *mlx, t_scene *scene);
void	state_destroy(t_state *self);
int		state_update(t_state *self);

#endif
