/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:13:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 15:12:39 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "bool.h"
# include "image.h"
# include "scene.h"
# include "sprite_bonus.h"

typedef struct s_view
{
	mlx_t		*mlx;
	t_image		frame;
	t_sprite	sprite;
}	t_view;

_Bool	view_create(t_view *self, mlx_t *mlx);
void	view_destroy(t_view *self);
void	view_draw(t_view *self, t_scene *scene);
void	view_draw_background(t_image *image, t_scene *scene);

#endif
