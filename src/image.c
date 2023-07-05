/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:15:30 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/05 14:08:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "image.h"

void	image_put_pixel(t_image *image, int x, int y, t_color color)
{
	unsigned int	*addr;

	addr = (unsigned int *)image->addr;
	addr[y * image->width + x] = color.value;
}

BOOL	image_create(t_image *image, void *mlx, int width, int height)
{
	int	endian;
	int	bpp;
	int	bpl;

	ft_bzero(image, sizeof(t_image));
	image->mlx = mlx;
	image->img = mlx_new_image(mlx, width, height);
	if (!image->img)
		return (FALSE);
	image->addr = mlx_get_data_addr(image->img, &bpp, &bpl, &endian);
	if (!image->addr)
		return (FALSE);
	image->width = width;
	image->height = height;
	return (TRUE);
}

void	image_clear(t_image *image)
{
	ft_bzero(image->addr, image->width * image->height * 4);
}

void	image_destroy(t_image *image)
{
	if (image && image->img)
		mlx_destroy_image(image->mlx, image->img);
	*image = (t_image){0};
}
