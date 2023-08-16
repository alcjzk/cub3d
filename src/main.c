/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:05:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/16 04:43:37 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include "scene.h"
#include "state.h"
#include "event.h"
#include "hook.h"
#include "texture.h"
#include "main.h"

int	main(int argc, char **argv)
{
	t_state				state;
	t_scene				scene;

	scene = (t_scene){0};
	scene.is_valid = TRUE;
	if (argc != 2 || validate(&scene, argv[1]))
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	texture_options_validate(&scene.texture_options);
	texture_pack_load(&scene.textures, &scene.texture_options);
	if (!scene.textures.is_valid)
	{
		scene_destroy(&scene);
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
	if (mlx_image_to_window(
		state.mlx,
		state.view.frame.img,
		0, 0)
		== -1)
	{
		state_destroy(&state);
		mlx_terminate(state.mlx);
		return (EXIT_FAILURE);
	}
	mlx_close_hook(state.mlx, (mlx_closefunc)on_destroy, &state);
	mlx_key_hook(state.mlx, (mlx_keyfunc)key_hook, &state);
	if (!mlx_loop_hook(state.mlx, (void (*)(void *))state_update, &state))
	{
		state_destroy(&state);
		mlx_terminate(state.mlx);
		return (EXIT_FAILURE);
	}
	mlx_loop(state.mlx);
	state_destroy(&state);
	mlx_terminate(state.mlx);
	return (EXIT_SUCCESS);
}
