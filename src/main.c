/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:05:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/11 16:44:27 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "scene.h"
#include "state.h"
#include "window.h"
#include "event.h"
#include "hook.h"
#include "main.h"

int	main(int argc, char **argv)
{
	void		*mlx;
	t_state		state;
	t_scene		scene;

	scene = (t_scene){0};
	scene.is_valid = TRUE;
	if (argc != 2 || validate(&scene, argv[1]))
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
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
