/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/04 14:31:08 by emajuri          ###   ########.fr       */
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

void	scene_destroy(t_scene *scene)
{
	if (scene->north_texture_path)
		free(scene->north_texture_path);
	if (scene->south_texture_path)
		free(scene->south_texture_path);
	if (scene->west_texture_path)
		free(scene->west_texture_path);
	if (scene->east_texture_path)
		free(scene->east_texture_path);
	map_destroy(&scene->map);
}

int	scene_create(t_scene *scene, char *file)
{
	int	fd;

	scene = (t_scene *){0};
	scene->is_valid = TRUE;
	if (validate_name(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	scene->is_valid = get_elements(scene, fd);
	scene->is_valid = map_create(&scene->map, fd, scene);
	close(fd);
	if (!scene->is_valid)
	{
		scene_destroy(scene);
		return (-1);
	}
	return (0);
}
