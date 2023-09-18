/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_textured.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:56:19 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/18 16:09:46 by emajuri          ###   ########.fr       */
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
			t_scene *scene,
			t_ray *ray);

void	line_textured_draw(t_line_textured *self, t_view *view, int x);

#endif
