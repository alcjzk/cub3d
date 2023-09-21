/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:44:05 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 17:14:43 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "state.h"
# include "line_textured.h"
# include <stdlib.h>

_Bool	view_create(t_view *self, mlx_t *mlx)
{
	*self = (t_view){};
	self->mlx = mlx;
	self->z_buffer = malloc(WINDOW_WIDTH * sizeof(float));
	if (!self->z_buffer)
		return (FALSE);
	if (!image_create(&self->frame, self->mlx, WINDOW_WIDTH, WINDOW_HEIGHT))
		return (FALSE);
	return (TRUE);
}

void	view_destroy(t_view *self)
{
	if (!self)
		return ;
	if (self->z_buffer)
		free(self->z_buffer);
	*self = (t_view){};
}

static void	draw_frame(t_view *self, t_scene *scene)
{
	int					x;
	t_ray				ray;
	t_line_textured		line;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		player_raydir_calc(&scene->player, x);
		ray = (t_ray){};
		ray_init(&ray, scene);
		ray_cast(&ray, scene);
		self->z_buffer[x] = ray.perp_wall_dist;
		line = (t_line_textured){};
		line_textured_init(&line, scene, &ray);
		line_textured_draw(&line, self, x);
		x++;
	}
}

void	view_draw(t_view *self, t_scene *scene)
{
	t_sprite_draw	sprite_draw;
	size_t			i;

	view_draw_background(&self->frame, scene);
	draw_frame(self, scene);
	i = 0;
	scene_sort_sprites(scene);
	while (i < scene->sprites->length)
	{
		sprite_draw_init(
			&sprite_draw,
			scene->sprites_sorted[i],
			&scene->player);
		sprite_draw_draw(&sprite_draw, self->z_buffer, &self->frame);
		i++;
	}
}

#endif
