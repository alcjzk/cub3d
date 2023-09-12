/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:03:49 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/12 15:43:08 by emajuri          ###   ########.fr       */
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
	BOOL		is_mouse_captured;
	t_minimap	minimap;
	BOOL		is_valid;
}	t_state;

BOOL	state_create(t_state *self, t_scene *scene);
void	state_destroy(t_state *self);
void	state_update(t_state *self);

#endif
