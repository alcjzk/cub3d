/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:14:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 17:17:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include "MLX42.h"
# include "bool.h"
# include "color.h"

typedef struct s_image
{
	mlx_t				*mlx;
	mlx_image_t			*img;
	int					width;
	int					height;
	_Bool				is_valid;
}t_image;

_Bool		image_create(t_image *self, mlx_t *mlx, int width, int height);
void		image_destroy(t_image *self);
void		image_clear(t_image *self);
void		image_put_pixel(t_image *self, int x, int y, t_color color);

#endif
