/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/20 17:32:46 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "unistd.h"
#include "fcntl.h"
#include "libft.h"
#include "texture.h"

_Bool	scene_is_valid_name(char *file)
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
		return (FALSE);
	}
	return (TRUE);
}


void	scene_free_buffer(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		free(buffer[i++]);
	free(buffer);
}

void	scene_buffer_remove_newlines(char **buffer)
{
	size_t	line_len;
	size_t	i;

	i = 0;
	while (buffer[i])
	{
		line_len = ft_strlen(buffer[i]);
		if (buffer[i][line_len - 1] == '\n')
			buffer[i][line_len - 1] = '\0';
		i++;
	}
}

#ifndef BONUS_FEATURES

_Bool	scene_create(t_scene *self, char *file)
{
	int		fd;
	char	**buffer;

	*self = (t_scene){.is_valid = TRUE};
	if (!scene_is_valid_name(file))
		return (FALSE);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	self->is_valid = scene_read(fd, &buffer);
	close(fd);
	scene_buffer_remove_newlines(buffer);
	self->is_valid = scene_set_options(self, buffer);
	self->is_valid = map_create(&self->map, self, buffer);
	self->is_valid = scene_is_colors_set(self);
	scene_free_buffer(buffer);
	if (self->is_valid)
		texture_options_validate(&self->texture_options);
	self->is_valid = texture_pack_load(&self->textures, &self->texture_options);
	if (!self->is_valid)
		scene_destroy(self);
	return (self->is_valid);
}

void	scene_destroy(t_scene *self)
{
	texture_options_free(&self->texture_options);
	texture_pack_unload(&self->textures);
	map_destroy(&self->map);
	*self = (t_scene){};
}

#endif
