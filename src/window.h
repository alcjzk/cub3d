/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:56:18 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/04 15:59:59 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <stddef.h>
# include "bool.h"

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define WINDOW_TITLE	"Cub3D"

typedef struct s_windows
{
	void	*mlx;
	void	*window;
}	t_window;

t_window	*window_create(
				t_window *self,
				void *mlx_ptr);
void		window_destroy(t_window *self);

#endif
