/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:05:27 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/04 17:39:38 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATE_H
# define STATE_H

# include <mlx.h>
# include "bool.h"
# include "window.h"

typedef struct s_state
{
	void		*mlx;
	t_window	window;
	BOOL		is_valid;
}	t_state;

BOOL	state_create(t_state *self, void *mlx);
void	state_destroy(t_state *self);

#endif
