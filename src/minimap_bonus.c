/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/25 18:29:07 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "minimap_bonus.h"

// void	minimap_update(t_image *minimap, t_player *player)
// {
// 	minimap_background_draw(minimap, width, height);
// 	minimap_wall_draw(scene, width, height);
// }

void	minimap_background_draw(t_minimap *self)
{
	int	map_row;
	int	map_col;

	map_row = 0;
	while (map_row <= (int)self->height)
	{
		map_col = 0;
		while (map_col <= (int)self->width)
		{
			if (map_row - BORDER_OFFSET < 0 ||
				map_row >= (int)self->height - BORDER_OFFSET ||
				map_col - BORDER_OFFSET < 0 ||
				map_col >= (int)self->width - BORDER_OFFSET)
				image_put_pixel(&self->map,
						map_col,
						map_row,
						(t_color){.value = BORDER});
			else
				image_put_pixel(&self->map,
						map_col,
						map_row,
						(t_color){.value = BACKGROUND});
			map_col++;
		}
		map_row++;
	}
}

void	minimap_block_draw(t_image *minimap, size_t map_col, size_t map_row, t_color wall)
{
	size_t	block_row;
	size_t	block_col;

	block_row = BORDER_OFFSET;
	while (block_row < BLOCK_SIZE + BORDER_OFFSET)
	{
		block_col = BORDER_OFFSET;
		while (block_col < BLOCK_SIZE + BORDER_OFFSET)
		{
			image_put_pixel(minimap,
				map_col * BLOCK_SIZE + block_col,
				map_row * BLOCK_SIZE + block_row,
				wall);
			block_col++;
		}
		block_row++;
	}
}

void	minimap_wall_draw(t_minimap *minimap, t_scene *scene)
{
	t_color	wall;
	size_t	map_row;
	size_t	map_col;

	map_row = 0;
	wall.value = WALL;
	while (map_row < (minimap->height - (BORDER_OFFSET * 2)) / BLOCK_SIZE)
	{
		map_col = 0;
		while (map_col < (minimap->width - (BORDER_OFFSET * 2)) / BLOCK_SIZE)
		{
			if (scene->map.map[map_row][map_col] == '1')
				minimap_block_draw(&minimap->map, map_col, map_row, wall);
			map_col++;
		}
		map_row++;
	}
}

BOOL	minimap_create(t_minimap *self, t_scene *scene, mlx_t *mlx)
{
	self->width = scene->map.width * BLOCK_SIZE + BORDER_OFFSET * 2;
	self->height = scene->map.height * BLOCK_SIZE + BORDER_OFFSET * 2;
	if (!image_create(&self->map, mlx, self->width, self->height))
		return (FALSE);
	if (mlx_image_to_window(
			mlx,
			self->map.img,
			0, 0)
		== -1)
	{
		return (FALSE);
	}
	mlx_set_instance_depth(self->map.img->instances, 1);
	minimap_background_draw(self);
	minimap_wall_draw(self, scene);
	return (TRUE);
}
