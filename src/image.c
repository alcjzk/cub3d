/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:15:30 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/31 18:23:18 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42.h"
#include "libft.h"
#include "image.h"

void	image_put_pixel(t_image *self, int x, int y, t_color color)
{
	mlx_put_pixel(self->img, x, y, color.value);
}

BOOL	image_create(t_image *self, mlx_t *mlx, int width, int height)
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
