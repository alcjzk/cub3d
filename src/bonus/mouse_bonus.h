/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:32:18 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/21 17:02:13 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_BONUS_H
# define MOUSE_BONUS_H

# include "MLX42.h"

void	mouse_align_center(mlx_t *mlx);
_Bool	mouse_is_inside_window(mlx_t *mlx);
_Bool	mouse_try_capture(mlx_t *mlx);
void	mouse_release(mlx_t *mlx);

#endif
