/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:46:07 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/19 18:43:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "color.h"

t_color	color_add_shadow(t_color color, float amount)
{
	float	color_scale;

	color_scale = fminf(amount + 0.1, 1);
	color.channels.r = (float)color.channels.r * color_scale;
	color.channels.g = (float)color.channels.g * color_scale;
	color.channels.b = (float)color.channels.b * color_scale;
	return (color);
}
