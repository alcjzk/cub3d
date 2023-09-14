/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:34:10 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/14 11:43:15 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "unistd.h"
#include "fcntl.h"
#include "libft.h"
#include "texture.h"
#include "vector.h"
#include "get_next_line.h"

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

int	scene_identifier_check(char *line)
{
	const char	*identifier[] = {"NO", "SO", "WE", "EA", "DR", "F", "C", NULL};
	int			i;

	i = 0;
	while (identifier[i])
	{
		if (!ft_strncmp(line, identifier[i], ft_strlen(identifier[i])))
			return (i);
		i++;
	}
	return (-1);
}

void	set_setters(func *identifier_functions)
{
	identifier_functions[0] = &scene_set_north;
	identifier_functions[1] = &scene_set_south;
	identifier_functions[2] = &scene_set_west;
	identifier_functions[3] = &scene_set_east;
	identifier_functions[4] = &scene_set_door;
	identifier_functions[5] = &scene_set_floor_color;
	identifier_functions[6] = &scene_set_ceiling_color;
}

BOOL	scene_set_textures(t_scene *self, char **buffer)
{
	size_t	i;
	int		function_index;
	func	identifier_functions[7];

	i = 0;
	if (!self->is_valid)
		return (FALSE);
	set_setters(identifier_functions);
	while (buffer[i])
	{
		buffer[i][ft_strlen(buffer[i]) - 1] = '\0';
		function_index = scene_identifier_check(buffer[i]);
		if (function_index != -1)
		{
			if (!identifier_functions[function_index](self, buffer[i]))
				printf("dup\n");
		}
		i++;
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
	close(fd);
	self->is_valid = scene_set_textures(self, buffer);
	self->is_valid = map_create(&self->map, self, buffer);
	return (-1);
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
