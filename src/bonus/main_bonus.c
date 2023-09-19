/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:05:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/18 18:49:33 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "MLX42.h"
# include <stdlib.h>
# include "scene.h"
# include "state.h"
# include "hook.h"
# include "texture.h"
# include "main.h"
# include "libft.h"
# include "map.h"

int	main(int argc, char **argv)
{
	t_state				state;
	t_scene				scene;

	if (argc != 2)
	{
		ft_putstr_fd("Incorrect amount of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (scene_create(&scene, argv[1]))
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
		state_destroy(&state);
		return (EXIT_FAILURE);
	}
	mlx_close_hook(state.mlx, (mlx_closefunc)on_close, state.mlx);
	mlx_key_hook(state.mlx, (mlx_keyfunc)map_door_toggle, state.scene);
	if (!mlx_loop_hook(state.mlx, (void (*)(void *))state_update, &state))
	{
		state_destroy(&state);
		return (EXIT_FAILURE);
	}
	mlx_loop(state.mlx);
	state_destroy(&state);
	return (EXIT_SUCCESS);
}

#endif