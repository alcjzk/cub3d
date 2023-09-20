/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 01:52:44 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 17:50:20 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_BONUS_H
# define SPRITE_BONUS_H

# define SPRITE_SCALE 2.5f

# include "MLX42.h"
# include "vec2f.h"
# include "player.h"
# include "image.h"
# include "vec2i.h"

typedef struct s_sprite
{
	t_vec2f			position;
	mlx_texture_t	*texture;
	float			distance_to_player;
}	t_sprite;

typedef struct s_sprite_draw
{
	t_vec2f		transform;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	int			sprite_frames;
	int			frame_offset;
	t_vec2i		start;
	t_vec2i		end;
	t_vec2i		texpos;
	t_sprite	*sprite;
}	t_sprite_draw;

void	sprite_create_test(t_sprite *self);
void	sprite_destroy(t_sprite *self);
t_vec2f	sprite_transform(t_sprite *self, t_player *player);
void	sprite_draw_init(
			t_sprite_draw *self,
			t_sprite *sprite,
			t_player *player);
void	sprite_draw_draw(t_sprite_draw *self, float *z_buffer, t_image *image);
void	sprite_update_distance_to_player(t_sprite *self, t_player *player);

#endif
