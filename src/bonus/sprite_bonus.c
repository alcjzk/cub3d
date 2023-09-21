/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:56:58 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 10:43:10 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "state.h"
# include "map.h"
# include "sprite_bonus.h"
# include <math.h>

void	sprite_destroy(t_sprite *self)
{
	mlx_delete_texture(self->texture);
	*self = (t_sprite){};
}

t_vec2f	sprite_transform(t_sprite *self, t_player *player)
{
	double	inverse_determinant;
	t_vec2f	transform;
	t_vec2f	sprite_position;

	sprite_position = vec2f_sub(self->position, player->position);
	inverse_determinant = 1.0 / (player->plane.x
			* player->direction.y
			- player->direction.x
			* player->plane.y);
	transform.x = inverse_determinant * (player->direction.y
			* sprite_position.x
			- player->direction.x
			* sprite_position.y);
	transform.y = inverse_determinant * (-player->plane.y
			* sprite_position.x
			+ player->plane.x
			* sprite_position.y);
	return (transform);
}

void	sprite_update_distance_to_player(t_sprite *self, t_player *player)
{
	self->distance_to_player
		= (player->position.x - self->position.x)
		* (player->position.x - self->position.x)
		+ (player->position.y - self->position.y)
		* (player->position.y - self->position.y);
}

#endif
