/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_doors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 16:49:30 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/18 18:52:33 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "map_bonus.h"
# include "libft.h"
# include "scene_bonus.h"

static BOOL	map_has_door(t_map *self)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (self->map[row])
	{
		col = 0;
		while (self->map[row][col])
		{
			if (self->map[row][col] == '2')
				return (TRUE);
			col++;
		}
		row++;
	}
	return (FALSE);
}

BOOL	map_door_save(t_map *self)
{
	size_t	i;

	if (!self->is_valid)
		return (FALSE);
	if (!map_has_door(self))
		return (TRUE);
	self->door_map = ft_calloc(self->height + 1, sizeof(char *));
	if (!self->door_map)
		return (FALSE);
	i = 0;
	while (i < self->height)
	{
		self->door_map[i] = ft_strdup(self->map[i]);
		if (!self->door_map[i])
		{
			while (i--)
				free(self->door_map[i]);
			free(self->door_map);
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static void	toggle_door(t_map *self, size_t y, size_t x)
{
	if (self->map[y][x] == '2')
		self->map[y][x] = '0';
	else
		self->map[y][x] = '2';
}

void	map_door_toggle(mlx_key_data_t keydata, t_scene *scene)
{
	size_t		player_x;
	size_t		player_y;
	t_map		*self;

	if (keydata.key == MLX_KEY_E && keydata.action == MLX_RELEASE)
	{
		self = &scene->map;
		if (self->door_map)
		{
			player_x = (size_t)scene->player.position.x;
			player_y = (size_t)scene->player.position.y;
			if (self->door_map[player_y][player_x + 1] == '2')
				toggle_door(self, player_y, player_x + 1);
			if (self->door_map[player_y][player_x - 1] == '2')
				toggle_door(self, player_y, player_x - 1);
			if (self->door_map[player_y + 1][player_x] == '2')
				toggle_door(self, player_y + 1, player_x);
			if (self->door_map[player_y - 1][player_x] == '2')
				toggle_door(self, player_y - 1, player_x);
		}
	}
}

#endif
