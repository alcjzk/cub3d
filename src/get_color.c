/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:12:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/01 17:33:08 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	numlen(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]) && i < 10)
		i++;
	return (i);
}

int	convert_nums(char *line, t_color *color)
{
	int		i;

	i = 0;
	if (numlen(&line[i]) > 3)
		return (-1);
	color->channels.r = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != ',')
		return (-1);
	i++;
	if (numlen(&line[i]) > 3)
		return (-1);
	color->channels.g = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != ',')
		return (-1);
	i++;
	if (numlen(&line[i]) > 3)
		return (-1);
	color->channels.b = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != '\n')
		return (-1);
	color->channels.a = 255;
	return (0);
}

int	get_color(t_scene *scene, char *line)
{
	int		i;
	t_color	color;

	i = 1;
	if (!line[1])
		return (-1);
	while (ft_isspace(line[i]))
		i++;
	if (convert_nums(&line[i], &color))
		return (-1);
	if (line[0] == 'F')
		scene->floor_color = color;
	else
		scene->ceiling_color = color;
	return (0);
}
