/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:34:04 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/05 20:36:30 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void	map_free(t_vector *tmpmap)
{
	size_t	i;

	i = 0;
	while (i < tmpmap->length)
		free(((char **)tmpmap->buffer)[i++]);
	vector_free(tmpmap);
}

char	**map_from_vec(t_vector *tmpmap)
{
	char		**map;

	map = NULL;
	if (!vector_push(tmpmap, &map))
	{
		map_free(tmpmap);
		return (NULL);
	}
	map = (char **)tmpmap->buffer;
	free(tmpmap);
	return (map);
}

char	**get_map(int fd, char *line)
{
	t_vector	*tmpmap;
	size_t		i;

	tmpmap = vector_with_capacity(1, sizeof(char *));
	while (line)
	{
		i = 0;
		while (ft_isspace(line[i]))
			i++;
		if (!line[i])
		{
			map_free(tmpmap);
			free(line);
			return (NULL);
		}
		line[ft_strlen(line) - 1] = '\0';
		if (!vector_push(tmpmap, &line))
		{
			map_free(tmpmap);
			return (NULL);
		}
		line = get_next_line(fd);
	}
	return (map_from_vec(tmpmap));
}
