/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:34:10 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/13 15:27:11 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "unistd.h"
#include "fcntl.h"
#include "libft.h"
#include "texture.h"
#include "vector.h"
#include "get_next_line.h"
#include <stdio.h>

static void	buffer_free(t_vector *buffer)
{
	size_t	i;

	i = 0;
	while (i < buffer->length)
		free(((char **)buffer->buffer)[i++]);
	vector_free(buffer);
}

BOOL	scene_read(int fd, char ***buffer)
{
	t_vector	*vec;
	char		*line;

	vec = vector_with_capacity(1, sizeof(char *));
	if (!vec)
		return (FALSE);
	line = get_next_line(fd);
	while (line)
	{
		if (!vector_push(vec, &line))
		{
			buffer_free(vec);
			free(line);
			return (FALSE);
		}
		line = get_next_line(fd);
	}
	if (!vector_push(vec, &line))
	{
		buffer_free(vec);
		return (FALSE);
	}
	*buffer = (char **)vec->buffer;
	free(vec);
	return (TRUE);
}

BOOL	scene_set_textures(t_scene *self, char **buffer)
{
	size_t	i;

	i = 0;
	if (!self->is_valid)
		return (FALSE);
	while (buffer[i])
	{
		buffer[i][ft_strlen(buffer[i]) - 1] = '\0';
		printf("%s\n", buffer[i++]);
	}
	return (TRUE);
}

int	scene_create(t_scene *self, char *file)
{
	int			fd;
	char		**buffer;

	*self = (t_scene){.is_valid = TRUE};
	if (validate_name(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	self->is_valid = scene_read(fd, &buffer);
	printf("%s\n", self->is_valid ? "Read file succesfully" : "Error while reading file");
	close(fd);
	self->is_valid = scene_set_textures(self, buffer);
	return (-1);
	// self->is_valid = get_elements(self, fd);
	// self->is_valid = map_create(&self->map, fd, self);
	// if (self->is_valid)
	// 	texture_options_validate(&self->texture_options);
	// self->is_valid = texture_pack_load(&self->textures, &self->texture_options);
	// if (!self->is_valid)
	// {
	// 	scene_print_error(self);
	// 	scene_destroy(self);
	// 	return (-1);
	// }
	return (0);
}
