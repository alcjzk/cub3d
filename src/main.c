/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:05:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 15:30:40 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include <stdlib.h>
#include "scene.h"
#include "state.h"
#include "hook.h"
#include "texture.h"
#include "main.h"
#include "libft.h"

int	main(int argc, char **argv)
{
	t_state				state;

	if (argc != 2)
	{
		ft_putstr_fd("Incorrect amount of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (!state_create(&state, argv[1]))
	{
		state_destroy(&state);
		return (EXIT_FAILURE);
	}
	mlx_loop(state.mlx);
	state_destroy(&state);
	return (EXIT_SUCCESS);
}
