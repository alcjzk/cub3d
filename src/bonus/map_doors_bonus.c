/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_doors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:49:30 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 16:59:56 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "map_bonus.h"
# include "scene_bonus.h"

static void	door_toggle(t_map *self, size_t y, size_t x)
{
	if (self->map[y][x] == '2')
		self->map[y][x] = '3';
	else if (self->map[y][x] == '3')
		self->map[y][x] = '2';
}

void	map_door_toggle(mlx_key_data_t keydata, t_scene *scene)
{
	size_t		player_x;
	size_t		player_y;

	if (keydata.key == MLX_KEY_E && keydata.action == MLX_RELEASE)
	{
		player_x = (size_t)scene->player.position.x;
		player_y = (size_t)scene->player.position.y;
		door_toggle(&scene->map, player_y, player_x + 1);
		door_toggle(&scene->map, player_y, player_x - 1);
		door_toggle(&scene->map, player_y + 1, player_x);
		door_toggle(&scene->map, player_y - 1, player_x);
	}
}

#endif
