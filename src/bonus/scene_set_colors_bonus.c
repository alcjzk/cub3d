/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_colors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:04:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/13 17:58:39 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

BOOL	scene_set_floor_color(t_scene *self, char *line)
{
	printf("setting floor\n");
	printf("%s\n", line);
	if (self->is_floor_color_set)
		printf("dupe\n");
	return (TRUE);
}

BOOL	scene_set_ceiling_color(t_scene *self, char *line)
{
	printf("setting ceiling\n");
	printf("%s\n", line);
	if (self->is_ceiling_color_set)
		printf("dupe\n");
	return (TRUE);
}
