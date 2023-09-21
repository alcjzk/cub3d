/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:49:04 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 17:04:43 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vector.h"
#include "get_next_line.h"

static void	vec_free(t_vector *buffer)
{
	size_t	i;

	i = 0;
	while (i < buffer->length)
		free(((char **)buffer->buffer)[i++]);
	vector_free(buffer);
}

_Bool	scene_read(int fd, char ***buffer)
{
	t_vector	*vec;
	char		*line;

	vec = vector_with_capacity(1, sizeof(char *));
	if (!vec)
		return (FALSE);
	line = get_next_line(fd);
	while (line)
	{
		if (!vector_push(vec, &line))
		{
			vec_free(vec);
			free(line);
			return (FALSE);
		}
		line = get_next_line(fd);
	}
	if (!vector_push(vec, &line))
	{
		vec_free(vec);
		return (FALSE);
	}
	*buffer = (char **)vec->buffer;
	free(vec);
	return (TRUE);
}
