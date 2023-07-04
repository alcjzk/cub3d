/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/04 13:29:25 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <fcntl.h>
#include <stdio.h>

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

int	get_texture(t_scene *scene, char *line)
{
	int		i;
	char	*copy;

	i = 2;
	if (!line[1] || !line[2])
		return (-1);
	while (ft_isspace(line[i]))
		i++;
	line[ft_strlen(line) - 1] = 0;
	copy = ft_strdup(&line[i]);
	if (!copy)
		return (-1);
	if (!ft_strncmp(line, "NO ", 3))
		scene->north_texture_path = copy;
	else if (!ft_strncmp(line, "SO ", 3))
		scene->south_texture_path = copy;
	else if (!ft_strncmp(line, "WE ", 3))
		scene->west_texture_path = copy;
	else if (!ft_strncmp(line, "EA ", 3))
		scene->east_texture_path = copy;
	else
		return (-1);
	return (0);
}

int	numlen(char *line)
{
	int	i;

	i = 0;
	while (ft_isdigit(line[i]) && i < 10)
		i++;
	return (i);
}

int	convert_nums(char *line, t_color *color)
{
	int		i;

	i = 0;
	if (numlen(&line[i]) > 3)
		return (-1);
	color->channels.r = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != ',')
		return (-1);
	i++;
	if (numlen(&line[i]) > 3)
		return (-1);
	color->channels.g = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != ',')
		return (-1);
	i++;
	if (numlen(&line[i]) > 3)
		return (-1);
	color->channels.b = ft_atoi(&line[i]);
	i += numlen(&line[i]);
	if (line[i] != '\n')
		return (-1);
	color->channels.a = 0;
	return (0);
}

int	get_color(t_scene *scene, char *line)
{
	int		i;
	t_color	color;

	i = 1;
	if (!line[1])
		return (-1);
	while (ft_isspace(line[i]))
		i++;
	if (convert_nums(&line[i], &color))
		return (-1);
	if (line[0] == 'F')
		scene->floor_color = color;
	else
		scene->ceiling_color = color;
	return (0);
}

int	get_elements(t_scene *scene, int fd)
{
	char	*line;
	int		i;
	int		count;

	line = NULL;
	i = -1;
	count = 0;
	while ((line && count < 6) || i < 0)
	{
		line = ft_get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (line[i])
		{
			if (line[i] == 'F' || line[i] == 'C')
			{
				if (get_color(scene, &line[i]))
					i = -1;
			}
			else if (get_texture(scene, &line[i]))
				i = -1;
			count++;
		}
		free(line);
		if (i < 0)
			return (-1);
	}
	return (0);
}

char	*skip_empty(int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = -1;
	while (line || i < 0)
	{
		line = ft_get_next_line(fd);
		if (!line)
			return (NULL);
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (line[i])
			break ;
	}
	return (line);
}

char	**get_map(int fd, char *line)
{
	char	**map;
	

	while (line)
	{
		printf("%s\n", line);
	}
	return (map);
}

int	get_map(t_scene *scene, int fd)
{
	char	*line;

	line = skip_empty(fd);
	scene->map = get_map(fd, line);
	(void)scene;
	return (0);
}

void	print_elem(t_scene *scene)
{
	printf("N: %s\n", scene->north_texture_path);
	printf("S: %s\n", scene->south_texture_path);
	printf("E: %s\n", scene->east_texture_path);
	printf("W: %s\n", scene->west_texture_path);
	printf("floor; a: %d, r: %d, g: %d, b: %d\n", scene->floor_color.channels.a, scene->floor_color.channels.r, scene->floor_color.channels.g, scene->floor_color.channels.b);
	printf("ceiling; a: %d, r: %d, g: %d, b: %d\n", scene->ceiling_color.channels.a, scene->ceiling_color.channels.r, scene->ceiling_color.channels.g, scene->ceiling_color.channels.b);
}

int	validate(t_scene *scene, char *file)
{
	int	fd;

	if (name_check(file))
		return (-1);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	get_elements(scene, fd);
	print_elem(scene);
	get_map(scene, fd);
	if (!scene->is_valid)
	{
		//free all
		return (-1);
	}
	return (0);
}
