/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:36:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 17:08:23 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "texture.h"

#ifndef BONUS_FEATURES

_Bool	texture_pack_load(
	t_texture_pack *self,
	const t_texture_options *options)
{
	if (!options->is_valid)
		return (FALSE);
	self->north = mlx_load_png(options->north);
	self->west = mlx_load_png(options->west);
	self->south = mlx_load_png(options->south);
	self->east = mlx_load_png(options->east);
	self->is_valid = texture_pack_is_valid(self);
	if (!self->is_valid)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		ft_putstr_fd("Some textures failed to load\n", STDERR_FILENO);
		texture_pack_unload(self);
		return (FALSE);
	}
	return (TRUE);
}

_Bool	texture_pack_is_valid(t_texture_pack *self)
{
	if (!texture_is_valid(self->north))
		return (FALSE);
	if (!texture_is_valid(self->west))
		return (FALSE);
	if (!texture_is_valid(self->south))
		return (FALSE);
	if (!texture_is_valid(self->east))
		return (FALSE);
	return (TRUE);
}

void	texture_pack_unload(t_texture_pack *self)
{
	if (self->north)
		mlx_delete_texture(self->north);
	if (self->west)
		mlx_delete_texture(self->west);
	if (self->south)
		mlx_delete_texture(self->south);
	if (self->east)
		mlx_delete_texture(self->east);
	*self = (t_texture_pack){0};
}

_Bool	texture_options_validate(t_texture_options *self)
{
	if (self->north && self->west && self->south && self->east)
	{
		self->is_valid = TRUE;
		return (TRUE);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Missing texture identifier\n", 2);
		self->is_valid = FALSE;
		return (FALSE);
	}
}

void	texture_options_free(t_texture_options *self)
{
	free(self->north);
	free(self->west);
	free(self->south);
	free(self->east);
	*self = (t_texture_options){0};
}

#endif
