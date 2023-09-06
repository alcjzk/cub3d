/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/06 12:23:50 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "minimap_bonus.h"
#include "state.h"

static t_color	get_color_of_pixel(t_minimap *self, size_t map_row, size_t map_col)
{
	if (map_row == self->height / 2 - BORDER_OFFSET * 2 && map_col == self->width / 2 - BORDER_OFFSET * 2)
		return ((t_color)PLAYER);
	return ((t_color)BACKGROUND);
}

void	minimap_background_draw(t_minimap *self)
{
	size_t	map_row;
	size_t	map_col;

	map_row = 0;
	while (map_row < self->height)
	{
		map_col = 0;
		while (map_col < self->width)
		{
			if (map_row - BORDER_OFFSET < 0 ||
				map_row >= self->height - BORDER_OFFSET ||
				map_col - BORDER_OFFSET < 0 ||
				map_col >= self->width - BORDER_OFFSET)
				image_put_pixel(&self->img,
						map_col,
						map_row,
						(t_color)BORDER);
			else
				image_put_pixel(&self->img,
						map_col,
						map_row,
						get_color_of_pixel(self, map_row, map_col));
			map_col++;
		}
		map_row++;
	}
}

void	minimap_wall_draw(t_minimap *self, float start_x, float start_y)
{
	size_t	img_y;
	size_t	img_x;
	float	map_x;
	float	map_y;

	img_y = 0;
	map_y = start_y;
	while (img_y < self->height- BORDER_OFFSET * 2)
	{
		img_x = 0;
		map_x = start_x;
		while (img_x < self->width- BORDER_OFFSET * 2)
		{
			if ((size_t)map_y < self->scene->map.height && (size_t)map_x < self->scene->map.width)
				if (self->scene->map.map[(size_t)map_y][(size_t)map_x] == '1')
					image_put_pixel(&self->img,
							img_x,
							img_y,
							(t_color)WALL);
			img_x++;
			map_x += 0.125f;
		}
		img_y++;
		map_y += 0.125f;
	}
}

float	get_x(size_t minimap_width, t_player *player)
{
	return (player->position.x - minimap_width / BLOCK_SIZE / 2);
}

float	get_y(size_t minimap_height, t_player *player)
{
	return (player->position.y - minimap_height / BLOCK_SIZE / 2);
}

BOOL	minimap_create(t_minimap *self, t_scene *scene, mlx_t *mlx)
{
	self->scene = scene;
	self->width = WINDOW_WIDTH / 4 + BORDER_OFFSET * 2;
	self->height =  WINDOW_HEIGHT / 4 + BORDER_OFFSET * 2;
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
	minimap_wall_draw(self, get_x(self->width, &self->scene->player), get_y(self->height, &self->scene->player));
	return (TRUE);
}

void	minimap_update(t_minimap *self)
{
	minimap_background_draw(self);
	minimap_wall_draw(self, get_x(self->width, &self->scene->player), get_y(self->height, &self->scene->player));
}
