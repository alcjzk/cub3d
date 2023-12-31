/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 04:15:35 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 15:03:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

ssize_t	vector_position(
	t_vector *self,
	_Bool (*cmp)(void *, void *),
	void *param)
{
	size_t	idx;
	void	*data;

	idx = 0;
	while (idx < self->length)
	{
		data = &self->buffer[self->elem_size * idx];
		if (cmp(data, param))
			return ((ssize_t)idx);
		idx++;
	}
	return (INVALID_INDEX);
}
