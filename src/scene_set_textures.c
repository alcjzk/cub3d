/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/14 15:44:35 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

BOOL	scene_set_north(t_scene *self, char *line)
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

BOOL	scene_set_south(t_scene *self, char *line)
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

BOOL	scene_set_west(t_scene *self, char *line)
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

BOOL	scene_set_east(t_scene *self, char *line)
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
