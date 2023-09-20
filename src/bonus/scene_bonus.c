/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:49:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 19:10:02 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <fcntl.h>
# include <unistd.h>
# include "scene.h"

void	scene_buffer_remove_newlines(char **buffer);
void	scene_free_buffer(char **buffer);
_Bool	scene_is_valid_name(char *file);

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
	self->is_valid = scene_is_colors_set(self);
	if (self->is_valid)
		texture_options_validate(&self->texture_options);
	self->is_valid = texture_pack_load(&self->textures, &self->texture_options);
	self->is_valid = map_create(&self->map, self, buffer);
	self->is_valid = scene_init_sprites(self);
	scene_free_buffer(buffer);
	if (!self->is_valid)
		scene_destroy(self);
	return (self->is_valid);
}

void	scene_destroy(t_scene *self)
{
	texture_options_free(&self->texture_options);
	texture_pack_unload(&self->textures);
	map_destroy(&self->map);
	scene_free_sprites(self);
	*self = (t_scene){};
}

#endif
