/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:09:04 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/04 17:54:07 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "state.h"
#include "window.h"
#include "event.h"
#include "hook.h"
#include "main.h"

int	main(void)
{
	void		*mlx;
	t_state		state;

	mlx = mlx_init();
	if (!mlx)
		return (EXIT_FAILURE);
	if (!state_create(&state, mlx))
	{
		state_destroy(&state);
		return (EXIT_FAILURE);
	}
	mlx_hook(state.window.window, EVENT_DESTROY, 0, on_destroy, &state);
	mlx_hook(state.window.window, EVENT_KEYUP, 0, on_keyup, &state);
	mlx_loop(state.mlx);
	return (EXIT_SUCCESS);
}
