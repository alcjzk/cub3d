/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_options.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:49:45 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/14 15:38:41 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

#ifndef BONUS_FEATURES

int	scene_get_function_index(char *line)
{
	const char	*identifier[] = {"NO", "SO", "WE", "EA", "F", "C", NULL};
	int			i;

	i = 0;
	while (identifier[i])
	{
		if (!ft_strncmp(line, identifier[i], ft_strlen(identifier[i])))
			return (i);
		i++;
	}
	return (-1);
}

void	init_option_functions(t_config_func *option_functions)
{
	option_functions[0] = &scene_set_north;
	option_functions[1] = &scene_set_south;
	option_functions[2] = &scene_set_west;
	option_functions[3] = &scene_set_east;
	option_functions[4] = &scene_set_floor_color;
	option_functions[5] = &scene_set_ceiling_color;
}

//TODO error handling for option functions
BOOL	scene_set_options(t_scene *self, char **buffer)
{
	size_t			i;
	int				function_index;
	t_config_func	option_functions[6];

	i = 0;
	if (!self->is_valid)
		return (FALSE);
	init_option_functions(option_functions);
	while (buffer[i])
	{
		buffer[i][ft_strlen(buffer[i]) - 1] = '\0';
		function_index = scene_get_function_index(buffer[i]);
		if (function_index != -1)
		{
			if (!option_functions[function_index](self, buffer[i]))
				i += 0; //error
		}
		i++;
	}
	return (TRUE);
}

#endif
