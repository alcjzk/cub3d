/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:49:45 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 17:04:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "scene.h"

#ifndef BONUS_FEATURES
# define CONFIG_FUNC_COUNT 6

t_scene_config_map_item	*scene_config_map(void)
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

static _Bool	scene_is_empty_line(char *line)
{
	size_t	i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i])
		return (FALSE);
	return (TRUE);
}

_Bool	scene_set_options(t_scene *self, char **buffer)
{
	t_scene_config_func	config_func;
	size_t				i;
	size_t				first_map_line;

	i = 0;
	first_map_line = map_find_first_line(buffer);
	if (!self->is_valid)
		return (FALSE);
	while (buffer[i])
	{
		config_func = scene_config_func(buffer[i]);
		if (!config_func)
		{
			if (i < first_map_line && !scene_is_empty_line(buffer[i]))
			{
				ft_putstr_fd("Error\n", 2);
				ft_putstr_fd("Found invalid identifier in the file\n", 2);
				return (FALSE);
			}
		}
		else if (!config_func(self, buffer[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
