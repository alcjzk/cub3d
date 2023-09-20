/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:36:40 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/20 16:06:50 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include <stdlib.h>
# include "texture.h"
# include "libft.h"

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
	self->door = mlx_load_png(options->door);
	self->sprite = mlx_load_png(options->sprite);
	if (!self->north
		|| !self->west
		|| !self->south
		|| !self->east
		|| !self->door
		|| !self->sprite)
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
	if (self->sprite)
		mlx_delete_texture(self->sprite);
	*self = (t_texture_pack){0};
}

_Bool	texture_options_validate(t_texture_options *self)
{
	if (self->north && self->west && self->south
		&& self->east && self->door && self->sprite)
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
	free(self->door);
	free(self->sprite);
	*self = (t_texture_options){0};
}

#endif
