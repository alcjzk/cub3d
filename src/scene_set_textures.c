/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/19 18:52:39 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

BOOL	scene_set_north(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;

	if (self->texture_options.north)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Found duplicate north identifier\n", 2);
		return (FALSE);
	}
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
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Found duplicate south identifier\n", 2);
		return (FALSE);
	}
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
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Found duplicate west identifier\n", 2);
		return (FALSE);
	}
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
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Found duplicate east identifier\n", 2);
		return (FALSE);
	}
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.east = dup;
	return (TRUE);
}
