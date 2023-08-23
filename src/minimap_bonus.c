/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/23 15:20:15 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

BOOL	minimap_create(t_scene *scene, mlx_t *mlx)
{
	size_t width;
	size_t height;

	width = scene->map.width * 8 + 2;
	height = scene->map.height * 8 + 2;

	if (!image_create(&scene->minimap, mlx, width, height))
		return (FALSE);
	if (mlx_image_to_window(
		mlx,
		scene->minimap.img,
		0, 0)
		== -1)
	{
		return (FALSE);
	}
	t_color red;
	red.channels.a = 255;
	red.channels.r = 255;
	red.channels.g = 0;
	red.channels.b = 0;

	t_color blue;
	blue.channels.a = 255;
	blue.channels.r = 0;
	blue.channels.g = 0;
	blue.channels.b = 255;

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			if (!i || !j || i == height - 1 || j == width - 1)
				image_put_pixel(&scene->minimap, j, i, red);
			else
				image_put_pixel(&scene->minimap, j, i, blue);
		}
	}

	t_color black;
	black.channels.a = 255;
	black.channels.r = 0;
	black.channels.g = 0;
	black.channels.b = 0;

	for (size_t i = 0; i < height / 8; i++)
	{
		for (size_t j = 0; j < width / 8; j++)
		{
			if (scene->map.map[i][j] == '1')
			{
				for (size_t y = 1; y <= 8; y++)
				{
					for (size_t x = 1; x <= 8; x++)
						image_put_pixel(&scene->minimap, j * 8 + x, i * 8 + y, black);
				}
			}
		}
	}
	return (TRUE);
}