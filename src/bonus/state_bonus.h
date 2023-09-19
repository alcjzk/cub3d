/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:03:49 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 17:17:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_BONUS_H
# define STATE_BONUS_H

// Bonus
# include "MLX42.h"
# include "bool.h"
# include "view.h"
# include "scene.h"
# include "minimap_bonus.h"

# define WINDOW_WIDTH	1600
# define WINDOW_HEIGHT	1200
# define WINDOW_TITLE	"Cub3D"

typedef struct s_state
{
	mlx_t		*mlx;
	t_view		view;
	t_scene		*scene;
	_Bool		is_mouse_captured;
	t_minimap	minimap;
	_Bool		is_valid;
}	t_state;

_Bool	state_create(t_state *self, t_scene *scene);
void	state_destroy(t_state *self);
void	state_update(t_state *self);

#endif
