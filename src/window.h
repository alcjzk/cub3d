/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:56:18 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 18:07:28 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stddef.h>
# include "bool.h"

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define WINDOW_TITLE	"Cub3D"

typedef struct s_window
{
	void	*mlx;
	void	*window;
}	t_window;

t_window	*window_create(
				t_window *self,
				void *mlx_ptr);
void		window_destroy(t_window *self);

#endif
