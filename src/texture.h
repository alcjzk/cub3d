/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 00:36:42 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/14 15:39:58 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H

# ifdef BONUS_FEATURES
#  include "texture_bonus.h"
# else

#  include "MLX42.h"
#  include "bool.h"

typedef struct s_texture_pack
{
	mlx_texture_t	*north;
	mlx_texture_t	*west;
	mlx_texture_t	*south;
	mlx_texture_t	*east;
	BOOL			is_valid;
}	t_texture_pack;

typedef struct s_texture_options
{
	char	*north;
	char	*west;
	char	*south;
	char	*east;
	BOOL	is_valid;
}	t_texture_options;

BOOL	texture_pack_load(
			t_texture_pack *self,
			const t_texture_options *options);
void	texture_pack_unload(t_texture_pack *self);

BOOL	texture_options_validate(t_texture_options *self);
void	texture_options_free(t_texture_options *self);

# endif
#endif
