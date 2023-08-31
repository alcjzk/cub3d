/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:33:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/08/31 14:49:03 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define PLAYER_YAW_SPEED 0.03
# define PLAYER_MOVE_SPEED 0.03

# include "MLX42.h"
# include "vec2f.h"
# include "keymap.h"
# include "bool.h"

typedef struct s_player
{
	t_vec2f	position;
	t_vec2f	direction;
	t_vec2f	raydir;
	t_vec2f	plane;
	double	yaw;
	BOOL	is_valid;
}	t_player;

void	player_init(t_player *self, char dir, int y, int x);
void	player_raydir_calc(t_player *self, int x);
void	player_update(t_player *self, mlx_t *mlx);
void	player_update_yaw(t_player *self, mlx_t *mlx);
t_vec2f	player_velocity(t_player *self, mlx_t *mlx);

#endif
