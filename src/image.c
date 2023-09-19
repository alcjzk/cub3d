/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:15:30 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 17:17:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "image.h"

void	image_put_pixel(t_image *self, int x, int y, t_color color)
{
	((t_color *)self->img->pixels)[self->img->width * y + x] = color;
}

_Bool	image_create(t_image *self, mlx_t *mlx, int width, int height)
{
	*self = (t_image){0};
	self->mlx = mlx;
	self->img = mlx_new_image(mlx, width, height);
	if (!self->img)
		return (FALSE);
	self->width = width;
	self->height = height;
	return (TRUE);
}

void	image_destroy(t_image *self)
{
	if (self && self->img)
		mlx_delete_image(self->mlx, self->img);
	*self = (t_image){0};
}
