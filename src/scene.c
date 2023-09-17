/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/14 16:17:40 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "unistd.h"
#include "fcntl.h"
#include "libft.h"
#include "texture.h"

int	validate_name(char *file)
{
	int	i;

	i = 0;
	while (file[i])
		i++;
	i -= 4;
	if (i < 0 || ft_strncmp(&file[i], ".cub", 4))
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Incorrect map name\n", 2);
		return (-1);
	}
	return (0);
}

void	scene_destroy(t_scene *self)
{
	texture_options_free(&self->texture_options);
	texture_pack_unload(&self->textures);
	map_destroy(&self->map);
}

static void	free_buffer(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		free(buffer[i++]);
	free(buffer);
}

int	scene_create(t_scene *self, char *file)
{
	int		fd;
	char	**buffer;

	*self = (t_scene){.is_valid = TRUE};
	if (validate_name(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	self->is_valid = scene_read(fd, &buffer);
	close(fd);
	self->is_valid = scene_set_options(self, buffer);
	self->is_valid = map_create(&self->map, self, buffer);
	free_buffer(buffer);
	if (self->is_valid)
		texture_options_validate(&self->texture_options);
	self->is_valid = texture_pack_load(&self->textures, &self->texture_options);
	if (!self->is_valid)
	{
		scene_print_error(self);
		scene_destroy(self);
		return (-1);
	}
	return (0);
}
