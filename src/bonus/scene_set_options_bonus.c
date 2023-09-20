/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_options_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:49:45 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/20 16:21:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "scene.h"

t_scene_config_map_item	*scene_config_map(void)
{
	static t_scene_config_map_item	map[CONFIG_FUNC_COUNT] = {
	{"NO", &scene_set_north},
	{"SO", &scene_set_south},
	{"WE", &scene_set_west},
	{"EA", &scene_set_east},
	{"F", &scene_set_floor_color},
	{"C", &scene_set_ceiling_color},
	{"DR", &scene_set_door},
	{"AS", &scene_set_sprite}
	};

	return (map);
}

#endif
