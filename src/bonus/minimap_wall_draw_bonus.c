/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_wall_draw_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:59:42 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/20 14:50:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "minimap_bonus.h"
# include "ray.h"

static float	get_x(size_t minimap_width, t_player *player)
{
	return (player->position.x
		- ((float)minimap_width - BORDER_OFFSET * 2)
		/ BLOCK_SIZE
		/ 2);
}

static float	get_y(size_t minimap_height, t_player *player)
{
	return (player->position.y
		- ((float)minimap_height - BORDER_OFFSET * 2)
		/ BLOCK_SIZE
		/ 2);
}

static _Bool	minimap_wall_validate(t_scene *scene, float map_x, float map_y)
{
	if (map_y >= 0 && map_x >= 0)
		if ((size_t)map_y < scene->map.height
			&& (size_t)map_x < scene->map.width)
			if (is_wall(scene->map.map[(size_t)map_y][(size_t)map_x])
				|| scene->map.map[(size_t)map_y][(size_t)map_x] == '3')
				return (TRUE);
	return (FALSE);
}

static t_color	minimap_color_decide(t_scene *scene, float map_x, float map_y)
{
	if (scene->map.map[(size_t)map_y][(size_t)map_x] == '1')
		return ((t_color)WALL);
	return ((t_color)DOOR);
}

void	minimap_wall_draw(t_minimap *self, t_scene *scene)
{
	size_t	img_y;
	size_t	img_x;
	float	map_x;
	float	map_y;

	img_y = BORDER_OFFSET;
	map_y = get_y(self->height, &scene->player);
	while (img_y < self->height - BORDER_OFFSET)
	{
		img_x = BORDER_OFFSET;
		map_x = get_x(self->width, &scene->player);
		while (img_x < self->width - BORDER_OFFSET)
		{
			if (minimap_wall_validate(scene, map_x, map_y))
				image_put_pixel(
					&self->img,
					img_x,
					img_y,
					minimap_color_decide(scene, map_x, map_y));
			img_x++;
			map_x += 1.0f / BLOCK_SIZE;
		}
		img_y++;
		map_y += 1.0f / BLOCK_SIZE;
	}
}

#endif
