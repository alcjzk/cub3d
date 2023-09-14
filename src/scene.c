/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/14 15:34:13 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "unistd.h"
#include "fcntl.h"
#include "libft.h"
#include "texture.h"
#include "vector.h"
#include "get_next_line.h"

int	validate_name(char *file)
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
	texture_options_free(&self->texture_options);
	texture_pack_unload(&self->textures);
	map_destroy(&self->map);
}

static void	vec_free(t_vector *buffer)
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
			vec_free(vec);
			free(line);
			return (FALSE);
		}
		line = get_next_line(fd);
	}
	if (!vector_push(vec, &line))
	{
		vec_free(vec);
		return (FALSE);
	}
	*buffer = (char **)vec->buffer;
	free(vec);
	return (TRUE);
}

int	scene_create(t_scene *self, char *file)
{
	int		fd;
	char	**buffer;
	size_t	i;

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
	i = 0;
	while (buffer[i])
		free(buffer[i++]);
	free(buffer);
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
