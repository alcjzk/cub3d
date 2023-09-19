/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:32:56 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 17:17:58 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "mouse_bonus.h"

void	mouse_align_center(mlx_t *mlx)
{
	mlx_set_mouse_pos(mlx, (mlx->width - 1) / 2, (mlx->height - 1) / 2);
}

_Bool	mouse_is_inside_window(mlx_t *mlx)
{
	int	mouse_dx;
	int	mouse_dy;

	mlx_get_mouse_pos(mlx, &mouse_dx, &mouse_dy);
	if (mouse_dx < 0 || mouse_dy < 0)
		return (FALSE);
	if (mouse_dx >= mlx->width || mouse_dy >= mlx->height)
		return (FALSE);
	return (TRUE);
}

_Bool	mouse_try_capture(mlx_t *mlx)
{
	if (mouse_is_inside_window(mlx))
	{
		mouse_align_center(mlx);
		mlx_set_cursor_mode(mlx, MLX_MOUSE_HIDDEN);
		return (TRUE);
	}
	return (FALSE);
}

void	mouse_release(mlx_t *mlx)
{
	mlx_set_cursor_mode(mlx, MLX_MOUSE_NORMAL);
}

#endif
