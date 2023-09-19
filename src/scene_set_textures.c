/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/19 17:17:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

_Bool	scene_set_north(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;

	if (self->texture_options.north)
		return (FALSE);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.north = dup;
	return (TRUE);
}

_Bool	scene_set_south(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;

	if (self->texture_options.south)
		return (FALSE);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.south = dup;
	return (TRUE);
}

_Bool	scene_set_west(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;

	if (self->texture_options.west)
		return (FALSE);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.west = dup;
	return (TRUE);
}

_Bool	scene_set_east(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;

	if (self->texture_options.east)
		return (FALSE);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.east = dup;
	return (TRUE);
}
