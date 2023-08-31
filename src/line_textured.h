/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_textured.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:56:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/08/30 09:08:47 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_TEXTURED_H
# define LINE_TEXTURED_H

# include "MLX42.h"
# include "view.h"
# include "ray.h"
# include "texture.h"

typedef struct s_line_textured
{
	mlx_texture_t	*texture;
	int				start;
	int				end;
	float			texture_x;
	float			texture_y;
	float			texture_step;
}	t_line_textured;

void	line_textured_init(
			t_line_textured *self,
			t_texture_pack *textures,
			t_player *player,
			t_ray *ray);

void	line_textured_draw(t_line_textured *self, t_view *view, int x);

#endif
