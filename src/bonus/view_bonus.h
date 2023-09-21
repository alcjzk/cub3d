/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:13:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 17:15:06 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_BONUS_H
# define VIEW_BONUS_H

# include "image.h"
# include "scene.h"

typedef struct s_view
{
	mlx_t		*mlx;
	t_image		frame;
	float		*z_buffer;
}	t_view;

_Bool	view_create(t_view *self, mlx_t *mlx);
void	view_destroy(t_view *self);
void	view_draw(t_view *self, t_scene *scene);
void	view_draw_background(t_image *image, t_scene *scene);

#endif
