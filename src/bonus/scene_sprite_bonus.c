/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_sprite_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:37:16 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 16:28:04 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

#include "sprite_bonus.h"
#include "scene.h"

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

_Bool	scene_init_sprites(t_scene *self)
{
	if (!self->is_valid)
		return (FALSE);
	self->sprites_sorted = malloc(self->sprites->length * sizeof(t_sprite *));
	if (!self->sprites_sorted)
		return (FALSE);
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
