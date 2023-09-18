/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:36:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/17 14:34:51 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <stdlib.h>
# include "texture.h"

BOOL	texture_pack_load(
	t_texture_pack *self,
	const t_texture_options *options)
{
	if (!options->is_valid)
		return (FALSE);
	self->north = mlx_load_png(options->north);
	self->west = mlx_load_png(options->west);
	self->south = mlx_load_png(options->south);
	self->east = mlx_load_png(options->east);
	self->door = mlx_load_png(options->door);
	if (!self->north
		|| !self->west
		|| !self->south
		|| !self->east
		|| !self->door)
	{
		texture_pack_unload(self);
		return (FALSE);
	}
	self->is_valid = TRUE;
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
	if (self->door)
		mlx_delete_texture(self->door);
	*self = (t_texture_pack){0};
}

BOOL	texture_options_validate(t_texture_options *self)
{
	if (self->north && self->west && self->south && self->east && self->door)
	{
		self->is_valid = TRUE;
		return (TRUE);
	}
	else
	{
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
	free(self->door);
	*self = (t_texture_options){0};
}

#endif