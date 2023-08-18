/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/18 15:24:01 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "unistd.h"
#include "fcntl.h"
#include "libft.h"

static int	validate_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i -= 4;
	if (i < 0)
		return (-1);
	if (ft_strncmp(&file[i], ".cub", 4))
		return (-1);
	return (0);
}

void	scene_destroy(t_scene *self)
{
	if (self->north_texture_path)
		free(self->north_texture_path);
	if (self->south_texture_path)
		free(self->south_texture_path);
	if (self->west_texture_path)
		free(self->west_texture_path);
	if (self->east_texture_path)
		free(self->east_texture_path);
	map_destroy(&self->map);
}

int	scene_create(t_scene *self, char *file)
{
	int	fd;

	*self = (t_scene){0};
	self->is_valid = TRUE;
	if (validate_name(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	self->is_valid = get_elements(self, fd);
	self->is_valid = map_create(&self->map, fd, self);
	close(fd);
	if (!self->is_valid)
	{
		scene_print_error(self);
		scene_destroy(self);
		return (-1);
	}
	return (0);
}
