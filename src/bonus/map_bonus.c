/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:58:38 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 20:00:44 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "libft.h"
# include "vec2i.h"
# include "scene.h"
# include "map.h"

_Bool	is_valid_map_char(char c);

_Bool	map_validate_symbols(
	t_map *self,
	t_player *player,
	t_scene *scene)
{
	t_vec2i	pos;

	pos.y = -1;
	if (!self->is_valid)
		return (FALSE);
	while (self->map[++(pos.y)])
	{
		pos.x = -1;
		while (self->map[pos.y][++(pos.x)])
		{
			if (ft_strchr(PLAYER_CHARS, self->map[pos.y][pos.x]))
			{
				if (player->is_valid)
					return (FALSE);
				player_init(player, self->map[pos.y][pos.x], pos.y, pos.x);
				self->map[pos.y][pos.x] = '0';
			}
			else if (self->map[pos.y][pos.x] == '4'
					&& !scene_add_sprite(scene, pos))
				return (FALSE);
			else if (!is_valid_map_char(self->map[pos.y][pos.x]))
				return (FALSE);
		}
	}
	return (player->is_valid);
}

#endif
