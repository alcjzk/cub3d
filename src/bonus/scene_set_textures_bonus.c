/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_textures_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/13 18:34:23 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

BOOL	scene_set_north(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;
	printf("setting north\n");
	printf("%s\n", line);
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
	printf("setting south\n");
	printf("%s\n", line);
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
	printf("setting west\n");
	printf("%s\n", line);
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
	printf("setting east\n");
	printf("%s\n", line);
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

BOOL	scene_set_door(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;
	printf("setting door\n");
	printf("%s\n", line);
	if (self->texture_options.door)
		return (FALSE);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.door = dup;
	return (TRUE);
}
