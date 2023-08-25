/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:34:04 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/25 14:58:47 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "vector.h"
#include "get_next_line.h"
#include "libft.h"

static void	tmpmap_free(t_vector *tmpmap)
{
	size_t	i;

	i = 0;
	while (i < tmpmap->length)
		free(((char **)tmpmap->buffer)[i++]);
	vector_free(tmpmap);
}

static char	map_from_vec(t_map *self, t_vector *tmpmap)
{
	size_t	height_max;
	size_t	width_max;
	void	*nullptr;

	nullptr = NULL;
	if (!vector_push(tmpmap, &nullptr))
	{
		tmpmap_free(tmpmap);
		return (FALSE);
	}
	self->map = (char **)tmpmap->buffer;
	height_max = 0;
	while (self->map[height_max])
	{
		width_max = 0;
		while (self->map[height_max][width_max])
			width_max++;
		if (width_max > self->width)
			self->width = width_max;
		height_max++;
	}
	self->height = height_max;
	free(tmpmap);
	return (TRUE);
}

BOOL	add_padding(t_map *self)
{
	int		i;
	char	*tmp;

	if (!self->is_valid)
		return (FALSE);
	i = 0;
	while (self->map[i])
	{
		tmp = ft_calloc(self->width + 1, sizeof(char));
		if (!tmp)
			return (FALSE);
		if (ft_strlcpy(tmp, self->map[i], self->width + 1) >= self->width + 1)
		{
			free(tmp);
			return (FALSE);
		}
		free(self->map[i]);
		self->map[i] = tmp;
		i++;
	}
	return (TRUE);
}

BOOL	map_read(t_map *self, int fd, char *line)
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
			self->is_valid = FALSE;
		line[ft_strlen(line) - 1] = '\0';
		if (!self->is_valid || !vector_push(tmpmap, &line))
		{
			tmpmap_free(tmpmap);
			free(line);
			return (FALSE);
		}
		line = get_next_line(fd);
	}
	self->is_valid = map_from_vec(self, tmpmap);
	self->is_valid = add_padding(self);
	return (self->is_valid);
}
