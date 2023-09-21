/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:03:49 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 15:27:46 by tjaasalo         ###   ########.fr       */
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
	t_scene		scene_real;
	_Bool		is_mouse_captured;
	t_minimap	minimap;
	_Bool		is_valid;
}	t_state;

_Bool	state_create(t_state *self, const char *config_path);
void	state_destroy(t_state *self);
void	state_update(t_state *self);

#endif
