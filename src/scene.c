/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/31 14:19:19 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "unistd.h"
#include "fcntl.h"
#include "libft.h"
#include "texture.h"

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
	texture_options_free(&self->texture_options);
	texture_pack_unload(&self->textures);
	map_destroy(&self->map);
}

int	scene_create(t_scene *self, char *file)
{
	int	fd;

	*self = (t_scene){};
	self->is_valid = TRUE;
	if (validate_name(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	self->is_valid = get_elements(self, fd);
	self->is_valid = map_create(&self->map, fd, self);
	close(fd);
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
