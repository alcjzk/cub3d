/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:05:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/18 15:31:56 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include "scene.h"
#include "state.h"
#include "event.h"
#include "hook.h"
#include "main.h"

int	main(int argc, char **argv)
{
	t_state		state;
	t_scene		scene;

	if (argc != 2 || scene_create(&scene, argv[1]))
		return (EXIT_FAILURE);
	if (!state_create(&state, &scene))
	{
		state_destroy(&state);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(
		state.mlx,
		state.view.frame.img,
		0, 0)
		== -1)
		{
			mlx_terminate(state.mlx);
			return (EXIT_FAILURE);
		}
	mlx_close_hook(state.mlx, (mlx_closefunc)on_destroy, &state);
	mlx_key_hook(state.mlx, (mlx_keyfunc)key_hook, &state);
	if (!mlx_loop_hook(state.mlx, (void (*)(void *))state_update, &state))
	{
		mlx_terminate(state.mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop(state.mlx);
	mlx_terminate(state.mlx);
	return (EXIT_SUCCESS);
}
