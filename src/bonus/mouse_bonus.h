/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:32:18 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/07 17:53:34 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_BONUS_H
# define MOUSE_BONUS_H

# include "MLX42.h"
# include "bool.h"

void	mouse_align_center(mlx_t *mlx);
BOOL	mouse_is_inside_window(mlx_t *mlx);
BOOL	mouse_try_capture(mlx_t *mlx);
void	mouse_release(mlx_t *mlx);

#endif
