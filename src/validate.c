/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/16 04:20:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	name_check(char *file)
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

void	scene_destroy(t_scene *scene)
{
	int	i;

	texture_options_free(&scene->texture_options);
	texture_pack_unload(&scene->textures);
	i = 0;
	if (scene->map)
		while (scene->map[i])
			free(scene->map[i++]);
	free(scene->map);
}

int	validate(t_scene *scene, char *file)
{
	int	fd;

	if (name_check(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	scene->is_valid = get_elements(scene, fd);
	scene->is_valid = validate_map(scene, fd);
	close(fd);
	if (!scene->is_valid)
	{
		scene_destroy(scene);
		return (-1);
	}
	return (0);
}
