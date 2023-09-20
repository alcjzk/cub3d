/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:05:27 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 14:50:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# ifdef BONUS_FEATURES
#  include "state_bonus.h"
# else

// Mandatory
#  include "MLX42.h"
#  include "bool.h"
#  include "view.h"
#  include "scene.h"

#  define WINDOW_WIDTH	1600
#  define WINDOW_HEIGHT	1200
#  define WINDOW_TITLE	"Cub3D"

typedef struct s_state
{
	mlx_t		*mlx;
	t_view		view;
	t_scene		*scene;
	_Bool		is_valid;
}	t_state;

_Bool	state_create(t_state *self, t_scene *scene);
void	state_destroy(t_state *self);
void	state_update(t_state *self);

# endif
#endif
