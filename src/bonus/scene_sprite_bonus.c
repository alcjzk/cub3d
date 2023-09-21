/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_sprite_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:37:16 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 19:11:37 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <stdlib.h>
# include "sprite_bonus.h"
# include "scene.h"

typedef int	(*t_cmp_func)(const void *, const void *);

int	sprite_cmp(const t_sprite **a, const t_sprite **b)
{
	if ((*a)->distance_to_player > (*b)->distance_to_player)
		return (-1);
	else if ((*a)->distance_to_player < (*b)->distance_to_player)
		return (1);
	return (0);
}

_Bool	scene_add_sprite(t_scene *self, t_vec2i position)
{
	t_sprite				sprite;

	if (!self->sprites)
		self->sprites = vector_with_capacity(1, sizeof(t_sprite));
	if (!self->sprites)
		return (FALSE);
	sprite.texture = self->textures.sprite;
	sprite.position.x = (float)position.x + 0.5f;
	sprite.position.y = (float)position.y + 0.5f;
	return (vector_push(self->sprites, &sprite));
}

void	scene_sort_sprites(t_scene *self)
{
	size_t	i;

	i = 0;
	while (i < self->sprites->length)
	{
		sprite_update_distance_to_player(
			self->sprites_sorted[i],
			&self->player);
		i++;
	}
	qsort(
		self->sprites_sorted,
		self->sprites->length,
		sizeof(t_sprite *),
		(t_cmp_func)sprite_cmp);
}

_Bool	scene_init_sprites(t_scene *self)
{
	size_t	i;

	if (!self->is_valid)
		return (FALSE);
	self->sprites_sorted = malloc(self->sprites->length * sizeof(t_sprite *));
	if (!self->sprites_sorted)
		return (FALSE);
	i = 0;
	while (i < self->sprites->length)
	{
		self->sprites_sorted[i] = (t_sprite *)vector_get(self->sprites, i);
		i++;
	}
	return (TRUE);
}

void	scene_free_sprites(t_scene *self)
{
	vector_free(self->sprites);
	self->sprites = NULL;
	free(self->sprites_sorted);
	self->sprites_sorted = NULL;
}

#endif
