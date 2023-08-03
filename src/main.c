/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:05:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/03 16:03:26 by emajuri          ###   ########.fr       */
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

	scene = (t_scene){0};
	scene.is_valid = TRUE;
	if (argc != 2 || validate(&scene, argv[1]))
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	printf("floor, r: %d, g: %d, b: %d, a: %d\n", scene.floor_color.channels.r, scene.floor_color.channels.g, scene.floor_color.channels.b, scene.floor_color.channels.a);
	printf("ceiling, r: %d, g: %d, b: %d, a: %d\n", scene.ceiling_color.channels.r, scene.ceiling_color.channels.g, scene.ceiling_color.channels.b, scene.ceiling_color.channels.a);
	if (!state_create(&state, &scene))
	{
		state_destroy(&state);
		return (EXIT_FAILURE);
	}
	draw_background(&state.view.frame, &scene);
	draw_frame(&state.view, &scene);
	if (mlx_image_to_window(
		state.mlx,
		state.view.frame.img,
		0, 0)
		== -1)
		{
			mlx_terminate(state.mlx);
			return (EXIT_FAILURE);
		}
	mlx_close_hook(state.mlx, on_destroy, &state);
	mlx_key_hook(state.mlx, key_hook, &state);
	if (!mlx_loop_hook(state.mlx, state_update, &state))
	{
		mlx_terminate(state.mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop(state.mlx);
	mlx_terminate(state.mlx);
	return (EXIT_SUCCESS);
}
