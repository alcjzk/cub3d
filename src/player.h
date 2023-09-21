/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:33:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 15:05:28 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_YAW_SPEED 2.3
# define PLAYER_MOVE_SPEED 3.0

# include "MLX42.h"
# include "vec2f.h"
# include "bool.h"

typedef struct s_state	t_state;

typedef struct s_player
{
	t_vec2f	position;
	t_vec2f	direction;
	t_vec2f	raydir;
	t_vec2f	plane;
	double	yaw;
	_Bool	is_valid;
}	t_player;

void	player_init(t_player *self, char dir, int y, int x);
void	player_raydir_calc(t_player *self, int x);
void	player_update(t_player *self, t_state *state);
void	player_update_yaw(t_player *self, t_state *state);
t_vec2f	player_velocity(t_player *self, mlx_t *mlx);

#endif
