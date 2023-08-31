/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/31 17:40:21 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "minimap_bonus.h"

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
				image_put_pixel(&self->img,
						map_col,
						map_row,
						(t_color)BORDER);
			else
				image_put_pixel(&self->img,
						map_col,
						map_row,
						(t_color)BACKGROUND);
			map_col++;
		}
		map_row++;
	}
}

void	minimap_block_draw(t_image *img, size_t map_col, size_t map_row, t_color color)
{
	size_t	block_row;
	size_t	block_col;

	block_row = BORDER_OFFSET;
	while (block_row < BLOCK_SIZE + BORDER_OFFSET)
	{
		block_col = BORDER_OFFSET;
		while (block_col < BLOCK_SIZE + BORDER_OFFSET)
		{
			image_put_pixel(img,
				map_col * BLOCK_SIZE + block_col,
				map_row * BLOCK_SIZE + block_row,
				color);
			block_col++;
		}
		block_row++;
	}
}

void	minimap_wall_draw(t_minimap *minimap, t_scene *scene)
{
	size_t	map_row;
	size_t	map_col;

	map_row = 0;
	while (map_row < (minimap->height - (BORDER_OFFSET * 2)) / BLOCK_SIZE)
	{
		map_col = 0;
		while (map_col < (minimap->width - (BORDER_OFFSET * 2)) / BLOCK_SIZE)
		{
			if (scene->map.map[map_row][map_col] == '1')
				minimap_block_draw(&minimap->img, map_col, map_row, (t_color)WALL);
			map_col++;
		}
		map_row++;
	}
}

BOOL	minimap_create(t_minimap *self, t_scene *scene, mlx_t *mlx)
{
	self->width = scene->map.width * BLOCK_SIZE + BORDER_OFFSET * 2;
	self->height = scene->map.height * BLOCK_SIZE + BORDER_OFFSET * 2;
	if (!image_create(&self->img, mlx, self->width, self->height))
		return (FALSE);
	if (mlx_image_to_window(
			mlx,
			self->img.img,
			0, 0)
		== -1)
	{
		return (FALSE);
	}
	mlx_set_instance_depth(self->img.img->instances, 1);
	minimap_background_draw(self);
	minimap_wall_draw(self, scene);
	return (TRUE);
}

void	minimap_player_draw(t_minimap *self, t_player *player)
{
	int len = 1;
	int	start = 0;
	for (int i = -4; i < 0; i++)
	{
		int j = 0;
		while (j < len)
		{
			image_put_pixel(&self->img,
				player->position.x * BLOCK_SIZE + j - start,
				player->position.y * BLOCK_SIZE + i,
				(t_color)PLAYER);
			j++;
		}
		start--;
		len += 2;
	}
	for (int i = 0; i < 5; i++)
	{
		int j = 0;
		while (j < len)
		{
			image_put_pixel(&self->img,
				player->position.x * BLOCK_SIZE + j - start,
				player->position.y * BLOCK_SIZE + i,
				(t_color)PLAYER);
			j++;
		}
		start++;
		len -= 2;
	}
}

void	minimap_update(t_minimap *self, t_scene *scene, t_player *player)
{
	minimap_background_draw(self);
	minimap_wall_draw(self, scene);
	minimap_player_draw(self, player);
}
