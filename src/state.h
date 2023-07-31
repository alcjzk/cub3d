/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:05:27 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/31 19:08:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include "MLX42.h"
# include "bool.h"
# include "view.h"
# include "scene.h"
# include "keymap.h"

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define WINDOW_TITLE	"Cub3D"

typedef struct s_state
{
	mlx_t		*mlx;
	t_view		view;
	t_scene		*scene;
	t_keymap	keymap;
	BOOL		is_valid;
}	t_state;

BOOL	state_create(t_state *self, t_scene *scene);
void	state_destroy(t_state *self);
void	state_update(void *param);

#endif
