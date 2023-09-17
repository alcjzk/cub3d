/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:49:45 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/17 15:55:47 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

#ifndef BONUS_FEATURES
# define CONFIG_FUNC_COUNT 6

static t_scene_config_map_item	*scene_config_map(void)
{
	static t_scene_config_map_item	map[CONFIG_FUNC_COUNT] = {
	{"NO", &scene_set_north},
	{"SO", &scene_set_south},
	{"WE", &scene_set_west},
	{"EA", &scene_set_east},
	{"F", &scene_set_floor_color},
	{"C", &scene_set_ceiling_color}
	};

	return (map);
}

#endif

static t_scene_config_func	scene_config_func(const char *identifier)
{
	int								i;
	const char						*ident;
	static t_scene_config_map_item	*map;

	i = 0;
	map = scene_config_map();
	while (i < CONFIG_FUNC_COUNT)
	{
		ident = map[i].identifier;
		if (ft_strncmp(identifier, ident, ft_strlen(ident)) == 0)
			return (map[i].func);
		i++;
	}
	return (NULL);
}

BOOL	scene_set_options(t_scene *self, char **buffer)
{
	size_t				i;
	t_scene_config_func	config_func;

	i = 0;
	if (!self->is_valid)
		return (FALSE);
	while (buffer[i])
	{
		buffer[i][ft_strlen(buffer[i]) - 1] = '\0';
		config_func = scene_config_func(buffer[i]);
		if (config_func && !config_func(self, buffer[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
