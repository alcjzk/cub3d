/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 07:14:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/05 15:52:29 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stddef.h>
# include "bool.h"
# include "color.h"

typedef struct s_image
{
	void				*mlx;
	void				*img;
	char				*addr;
	int					width;
	int					height;
	BOOL				is_valid;
}	t_image;

BOOL		image_create(t_image *image, void *mlx, int width, int height);
void		image_destroy(t_image *image);
void		image_clear(t_image *image);
void		image_put_pixel(t_image *image, int x, int y, t_color color);

#endif
