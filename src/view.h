/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:13:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/14 15:40:59 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEW_H
# define VIEW_H

# include "bool.h"
# include "image.h"
# include "scene.h"

typedef struct s_view
{
	mlx_t	*mlx;
	t_image	frame;
}	t_view;

BOOL	view_create(t_view *self, mlx_t *mlx);
void	view_destroy(t_view *self);
void	view_draw(t_view *self, t_scene *scene);

#endif
