/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:34:10 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/13 14:22:06 by emajuri          ###   ########.fr       */
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

t_vector	*scene_read(int fd)
{
	t_vector	*buffer;
	char		*line;

	line = get_next_line(fd);
	printf("Got line:\n%s", line);
	if (line)
	{
		buffer = vector_with_capacity(1, sizeof(char *));
		if (!buffer)
		{
			free(line);
			return (NULL);
		}
	}
	while (line)
	{
		if (!vector_push(buffer, &line))
		{
			buffer_free(buffer);
			free(line);
			return (NULL);
		}
		line = get_next_line(fd);
		printf("Got line:\n%sbuf len: %zu\n", line, buffer->length);
	}
	return (buffer);
}

BOOL	set_textures(t_scene *self, t_vector *buffer)
{
	if (!self->is_valid)
		return (FALSE);
	for (size_t i = 0; i < buffer->length; i++)
		printf("%s", ((char **)buffer->buffer)[i]);
	return (TRUE);
}

int	scene_create(t_scene *self, char *file)
{
	int			fd;
	t_vector	*buffer;

	*self = (t_scene){.is_valid = TRUE};
	if (validate_name(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	buffer = scene_read(fd);
	if (!buffer)
		self->is_valid = FALSE;
	printf("%s\nbuffer len: %zu\n", self->is_valid ? "Read file succesfully" : "Error while reading file", buffer->length);
	close(fd);
	self->is_valid = set_textures(self, buffer);
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
