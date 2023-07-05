/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/05 21:04:48 by emajuri          ###   ########.fr       */
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

void	validate_error(t_scene *scene)
{
	int	i;

	if (scene->north_texture_path)
		free(scene->north_texture_path);
	if (scene->south_texture_path)
		free(scene->south_texture_path);
	if (scene->west_texture_path)
		free(scene->west_texture_path);
	if (scene->east_texture_path)
		free(scene->east_texture_path);
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
		validate_error(scene);
		return (-1);
	}
	return (0);
}
