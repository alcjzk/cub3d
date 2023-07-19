/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:33:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 14:17:55 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vec2f.h"
# include "bool.h"

typedef struct s_player
{
	t_vec2f	position;
	t_vec2f	direction;
	t_vec2f	camera;
	t_vec2f	raydir;
	t_vec2f	plane;
	BOOL	is_valid;
}	t_player;

void	player_init(t_player *self, char dir, int y, int x);

#endif
