/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:14:10 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/16 04:22:39 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	set_texture(t_scene *scene, char *line, char *copy)
{
	if (!ft_strncmp(line, "NO ", 3) && !scene->texture_options.north)
		scene->texture_options.north = copy;
	else if (!ft_strncmp(line, "SO ", 3) && !scene->texture_options.south)
		scene->texture_options.south = copy;
	else if (!ft_strncmp(line, "WE ", 3) && !scene->texture_options.west)
		scene->texture_options.west = copy;
	else if (!ft_strncmp(line, "EA ", 3) && !scene->texture_options.east)
		scene->texture_options.east = copy;
	else
		return (-1);
	return (0);
}

int	get_texture(t_scene *scene, char *line)
{
	int		i;
	char	*copy;

	i = 2;
	if (!line[1] || !line[2])
		return (-1);
	while (ft_isspace(line[i]))
		i++;
	line[ft_strlen(line) - 1] = '\0';
	copy = ft_strdup(&line[i]);
	if (!copy)
		return (-1);
	if (set_texture(scene, line, copy))
	{
		free(copy);
		return (-1);
	}
	return (0);
}

int	get_element(t_scene *scene, char *line, int i)
{
	if (line[i])
	{
		if (line[i] == 'F' || line[i] == 'C')
		{
			if (get_color(scene, &line[i]))
				return (-42);
		}
		else if (get_texture(scene, &line[i]))
			return (-42);
		return (1);
	}
	return (0);
}

BOOL	get_elements(t_scene *scene, int fd)
{
	char	*line;
	int		i;
	int		count;

	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		count += get_element(scene, line, i);
		free(line);
		if (count < 0)
			return (FALSE);
		if (count == 6)
			break ;
		line = get_next_line(fd);
	}
	if (!scene->texture_options.north) // TODO: What is this for?
		return (FALSE);
	return (TRUE);
}
