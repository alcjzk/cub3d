/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_colors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:04:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/19 17:17:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

static int	numlen(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]) && i < 5)
		i++;
	return (i);
}

static _Bool	convert_nums(char *line, t_color *color)
{
	int		i;

	i = 0;
	if (numlen(&line[i]) > 3)
		return (FALSE);
	color->channels.r = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != ',')
		return (FALSE);
	i++;
	if (numlen(&line[i]) > 3)
		return (FALSE);
	color->channels.g = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != ',')
		return (FALSE);
	i++;
	if (numlen(&line[i]) > 3)
		return (FALSE);
	color->channels.b = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != '\0')
		return (FALSE);
	color->channels.a = 255;
	return (TRUE);
}

_Bool	scene_set_floor_color(t_scene *self, char *line)
{
	if (self->is_floor_color_set)
		return (FALSE);
	line++;
	while (ft_isspace(*(line)))
		line++;
	if (!convert_nums(line, &self->floor_color))
		return (FALSE);
	self->is_floor_color_set = TRUE;
	return (TRUE);
}

_Bool	scene_set_ceiling_color(t_scene *self, char *line)
{
	if (self->is_ceiling_color_set)
		return (FALSE);
	line++;
	while (ft_isspace(*(line)))
		line++;
	if (!convert_nums(line, &self->ceiling_color))
		return (FALSE);
	self->is_ceiling_color_set = TRUE;
	return (TRUE);
}
