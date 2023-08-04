/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:14:10 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/04 17:06:02 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "get_next_line.h"
#include <stdlib.h>
#include "libft.h"

int	set_texture(t_scene *scene, char *line, char *copy)
{
	if (!ft_strncmp(line, "NO ", 3) && !scene->north_texture_path)
		scene->north_texture_path = copy;
	else if (!ft_strncmp(line, "SO ", 3) && !scene->south_texture_path)
		scene->south_texture_path = copy;
	else if (!ft_strncmp(line, "WE ", 3) && !scene->west_texture_path)
		scene->west_texture_path = copy;
	else if (!ft_strncmp(line, "EA ", 3) && !scene->east_texture_path)
		scene->east_texture_path = copy;
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
	if (!scene->north_texture_path)
		return (FALSE);
	return (TRUE);
}
