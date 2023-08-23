/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/23 16:13:17 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "minimap_bonus.h"

static void	init_color(t_color *color, size_t red, size_t green, size_t blue)
{
	color->channels.a = 255;
	color->channels.r = red;
	color->channels.g = green;
	color->channels.b = blue;
}

void	minimap_background_draw(t_image *minimap, size_t width, size_t height)
{
	t_color	border;
	t_color	background;
	size_t	i;
	size_t	j;

	i = 0;
	init_color(&border, 255, 0, 0);
	init_color(&background, 0, 0, 255);
	while (i <= height)
	{
		j = 0;
		while (j <= width)
		{
			if (!i || !j || i == height - 1 || j == width - 1)
				image_put_pixel(minimap, j, i, border);
			else
				image_put_pixel(minimap, j, i, background);
			j++;
		}
		i++;
	}
}

void	minimap_block_draw(t_image *minimap, size_t j, size_t i, t_color wall)
{
	size_t	y;
	size_t	x;

	y = 1;
	while (y <= BLOCK_SIZE)
	{
		x = 1;
		while (x <= BLOCK_SIZE)
		{
			image_put_pixel(minimap,
				j * BLOCK_SIZE + x,
				i * BLOCK_SIZE + y,
				wall);
			x++;
		}
		y++;
	}
}

void	minimap_wall_draw(t_scene *scene, size_t width, size_t height)
{
	t_color	wall;
	size_t	i;
	size_t	j;

	i = 0;
	init_color(&wall, 0, 0, 0);
	while (i < height / BLOCK_SIZE)
	{
		j = 0;
		while (j < width / BLOCK_SIZE)
		{
			if (scene->map.map[i][j] == '1')
				minimap_block_draw(&scene->minimap, j, i, wall);
			j++;
		}
		i++;
	}
}

BOOL	minimap_create(t_scene *scene, mlx_t *mlx)
{
	size_t		width;
	size_t		height;
	int const	border_offset = 2;

	width = scene->map.width * BLOCK_SIZE + border_offset;
	height = scene->map.height * BLOCK_SIZE + border_offset;
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
	minimap_background_draw(&scene->minimap, width, height);
	minimap_wall_draw(scene, width, height);
	return (TRUE);
}
