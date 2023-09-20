/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:19:13 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/20 14:50:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "scene.h"
# include "minimap_bonus.h"
# include "state.h"

void	minimap_background_draw(t_minimap *self)
{
	size_t	img_pixel_x;
	size_t	img_pixel_y;

	img_pixel_y = 0;
	while (img_pixel_y < self->height)
	{
		img_pixel_x = 0;
		while (img_pixel_x < self->width)
		{
			if (img_pixel_x < BORDER_OFFSET || img_pixel_y < BORDER_OFFSET
				|| img_pixel_y >= self->height - BORDER_OFFSET
				|| img_pixel_x >= self->width - BORDER_OFFSET)
				image_put_pixel(&self->img,
					img_pixel_x,
					img_pixel_y,
					(t_color)BORDER);
			else
				image_put_pixel(&self->img,
					img_pixel_x,
					img_pixel_y,
					(t_color)BACKGROUND);
			img_pixel_x++;
		}
		img_pixel_y++;
	}
}

void	minimap_player_draw(t_minimap *self, t_scene *scene)
{
	size_t	middle_x;
	size_t	middle_y;
	int		i;

	middle_y = self->height / 2;
	middle_x = self->width / 2;
	i = 2;
	while (++i <= 20)
		image_put_pixel(
			&self->img,
			middle_x + scene->player.direction.x * i + 0.5f,
			middle_y + scene->player.direction.y * i + 0.5f,
			(t_color)BORDER);
	i = -4;
	while (++i <= 3)
		image_put_pixel(&self->img, middle_x + i, middle_y, (t_color)PLAYER);
	i = -4;
	while (++i <= 3)
		image_put_pixel(&self->img, middle_x, middle_y + i, (t_color)PLAYER);
}

_Bool	minimap_create(t_minimap *self, t_scene *scene, mlx_t *mlx)
{
	self->width = WINDOW_WIDTH / 4 + BORDER_OFFSET * 2;
	self->height = WINDOW_HEIGHT / 4 + BORDER_OFFSET * 2;
	if (!image_create(&self->img, mlx, self->width, self->height))
		return (FALSE);
	if (mlx_image_to_window(
			mlx,
			self->img.img,
			0, 0)
		== -1)
	{
		return (FALSE);
	}
	mlx_set_instance_depth(self->img.img->instances, 1);
	minimap_background_draw(self);
	minimap_wall_draw(self, scene);
	minimap_player_draw(self, scene);
	return (TRUE);
}

void	minimap_update(t_minimap *self, t_scene *scene)
{
	minimap_background_draw(self);
	minimap_wall_draw(self, scene);
	minimap_player_draw(self, scene);
}

#endif
