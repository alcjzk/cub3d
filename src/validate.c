/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:57:28 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/05 18:35:26 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	line[ft_strlen(line) - 1] = '\0';
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

	line = NULL;
	i = -1;
	count = 0;
	while ((line && count < 6) || i < 0)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		count += get_element(scene, line, i);
		// if (line[i])
		// {
		// 	if (line[i] == 'F' || line[i] == 'C')
		// 	{
		// 		if (get_color(scene, &line[i]))
		// 			i = -1;
		// 	}
		// 	else if (get_texture(scene, &line[i]))
		// 		i = -1;
		// 	count++;
		// }
		free(line);
		if (count < 0)
			return (FALSE);
	}
	if (!scene->north_texture_path)
		return (FALSE);
	return (TRUE);
}

char	*skip_empty(int fd)
{
	char	*line;
	int		i;

	line = NULL;
	i = -1;
	while (line || i < 0)
	{
		line = get_next_line(fd);
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
	t_vector	*tmpmap;
	char		**map;
	size_t		i;

	tmpmap = vector_with_capacity(1, sizeof(char *));
	while (line)
	{
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (!line[i])
		{
			vector_free(tmpmap);
			free(line);
			return (NULL);
		}
		line[ft_strlen(line) - 1] = '\0';
		if (!vector_push(tmpmap, &line))
		{
			vector_free(tmpmap);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	i = 0;
	map = ft_calloc(tmpmap->length + 1, sizeof(char *));
	while (map && i < tmpmap->length)
	{
		map[i] = *(char **)vector_get(tmpmap, i);
		i++;
	}
	map[i] = NULL;
	vector_free(tmpmap);
	return (map);
}

BOOL	check_symbols(t_scene *scene, char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_strchr(" 01NSWE", map[y][x]))
				return (FALSE);
			if (ft_strchr("NSWE", map[y][x]))
			{
				if (scene->start)
					return (FALSE);
				scene->start = map[y][x];
				scene->player_x = x;
				scene->player_y = y;
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
	return (TRUE);
}

BOOL	check_wall_is_zero(int y, int x, char **map)
{
	if (map[y][x] == '0')
	{
		if (!map[y + 1])
			return (TRUE);
		else if (y == 0)
			return (TRUE);
		else if (x == 0)
			return (TRUE);
		else if (ft_strlen(map[y + 1]) < (size_t)x + 1)
			return (TRUE);
		else if (ft_strlen(map[y - 1]) < (size_t)x + 1)
			return (TRUE);
	}
	return (FALSE);
}

BOOL	check_walls(t_scene *scene, char **map)
{
	int	x;
	int	y;

	if (!scene->is_valid)
		return (FALSE);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (check_wall_is_zero(y, x, map))
				return (FALSE);
			if (map[y][x] == '0' &&
				(!ft_strchr("01", map[y - 1][x]) ||
				!ft_strchr("01", map[y + 1][x]) ||
				!ft_strchr("01", map[y][x - 1]) ||
				!ft_strchr("01", map[y][x + 1])))
				return (FALSE);
			x++;
		}
		y++;
	}
	return (TRUE);
}

void	change_chars(char **map)
{
	int	x;
	int	y;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '2')
				map[y][x] = '0';
			else if (map[y][x] == '3')
				map[y][x] = '1';
			x++;
		}
		y++;
	}
}

void	flood_fill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == '0')
		map[y][x] += 2;
	else
		return ;
	if (y != 0 && ft_strlen(map[y - 1]) >= (size_t)x)
		flood_fill(map, y - 1, x);
	if (map[y + 1] && ft_strlen(map[y + 1]) >= (size_t)x)
		flood_fill(map, y + 1, x);
	if (x != 0)
		flood_fill(map, y, x - 1);
	if (map[y][x + 1])
		flood_fill(map, y, x + 1);
}


BOOL check_connected(t_scene *scene, char **map)
{
	int	x;
	int	y;

	if (!scene->is_valid)
		return (FALSE);
	flood_fill(map, scene->player_y, scene->player_x);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || map[y][x] == '1')
				return (FALSE);
			x++;
		}
		y++;
	}
	change_chars(map);
	return (TRUE);
}

void	print_map(t_scene *scene)
{
	printf("\n");
	if (!scene->map)
		return ;
	for(int i = 0; scene->map[i]; i++)
		printf("%s\n", scene->map[i]);
}

BOOL	validate_map(t_scene *scene, int fd)
{
	char	*line;

	if (!scene->is_valid)
		return (FALSE);
	line = skip_empty(fd);
	scene->map = get_map(fd, line);
	if (!scene->map)
		return (FALSE);
	scene->is_valid = check_symbols(scene, scene->map);
	scene->is_valid = check_walls(scene, scene->map);
	scene->is_valid = check_connected(scene, scene->map);
	return (scene->is_valid);
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

void	print_elem(t_scene *scene)
{
	printf("N: %s\n", scene->north_texture_path);
	printf("S: %s\n", scene->south_texture_path);
	printf("E: %s\n", scene->east_texture_path);
	printf("W: %s\n", scene->west_texture_path);
	printf("floor; a: %d, r: %d, g: %d, b: %d\n", scene->floor_color.channels.a, scene->floor_color.channels.r, scene->floor_color.channels.g, scene->floor_color.channels.b);
	printf("ceiling; a: %d, r: %d, g: %d, b: %d\n", scene->ceiling_color.channels.a, scene->ceiling_color.channels.r, scene->ceiling_color.channels.g, scene->ceiling_color.channels.b);
	printf("start x: %d\n", scene->player_x);
	printf("start y: %d\n", scene->player_y);
	printf("start char: %c\n", scene->start);
	printf("valid: %s\n", scene->is_valid ? "TRUE" : "FALSE");
	print_map(scene);
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
	print_elem(scene);
	scene->is_valid = validate_map(scene, fd);
	print_elem(scene);
	close(fd);
	if (!scene->is_valid)
	{
		validate_error(scene);
		return (-1);
	}
	return (0);
}
