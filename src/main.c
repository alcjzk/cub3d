/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:05:47 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/05 20:26:54 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "scene.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	scene = (t_scene){0};
	scene.is_valid = TRUE;
	if (argc != 2 || validate(&scene, argv[1]))
	{
		printf("Error\n");
		return (-1);
	}
	return (0);
}
