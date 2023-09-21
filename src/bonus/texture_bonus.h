/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:49:49 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 10:40:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_BONUS_H
# define TEXTURE_BONUS_H

# include "MLX42.h"
# include "bool.h"

typedef struct s_texture_pack
{
	mlx_texture_t	*north;
	mlx_texture_t	*west;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	mlx_texture_t	*door;
	mlx_texture_t	*sprite;
	_Bool			is_valid;
}	t_texture_pack;

typedef struct s_texture_options
{
	char	*north;
	char	*west;
	char	*south;
	char	*east;
	char	*door;
	char	*sprite;
	_Bool	is_valid;
}	t_texture_options;

_Bool	texture_pack_load(
			t_texture_pack *self,
			const t_texture_options *options);
void	texture_pack_unload(t_texture_pack *self);
_Bool	texture_options_validate(t_texture_options *self);
void	texture_options_free(t_texture_options *self);
_Bool	texture_is_valid(mlx_texture_t *self);
_Bool	texture_pack_is_valid(t_texture_pack *self);

#endif
