/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_textures_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/13 17:46:19 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

BOOL	scene_set_north(t_scene *self, char *line)
{
	printf("setting north\n");
	printf("%s\n", line);
	if (self->texture_options.north)
		printf("dupe\n");
	self->texture_options.north = line;
	return (TRUE);
}

BOOL	scene_set_south(t_scene *self, char *line)
{
	printf("setting south\n");
	printf("%s\n", line);
	if (self->texture_options.south)
		printf("dupe\n");
	self->texture_options.south = line;
	return (TRUE);

}

BOOL	scene_set_west(t_scene *self, char *line)
{
	printf("setting west\n");
	printf("%s\n", line);
	if (self->texture_options.west)
		printf("dupe\n");
	self->texture_options.west = line;
	return (TRUE);

}

BOOL	scene_set_east(t_scene *self, char *line)
{
	printf("setting east\n");
	printf("%s\n", line);
	if (self->texture_options.east)
		printf("dupe\n");
	self->texture_options.east = line;
	return (TRUE);

}

BOOL	scene_set_door(t_scene *self, char *line)
{
	printf("setting door\n");
	printf("%s\n", line);
	if (self->texture_options.door)
		printf("dupe\n");
	self->texture_options.door = line;
	return (TRUE);
}
