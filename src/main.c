/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:05:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 16:53:19 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "state.h"

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
