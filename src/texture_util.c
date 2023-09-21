/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:36:08 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 10:36:49 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"

_Bool	texture_is_valid(mlx_texture_t *self)
{
	if (!self)
		return (FALSE);
	if (self->width % self->height != 0)
		return (FALSE);
	return (TRUE);
}
