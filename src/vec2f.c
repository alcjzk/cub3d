/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:07:27 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/23 15:30:18 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vec2f.h"

float	vec2f_dot(t_vec2f lhs, t_vec2f rhs)
{
	return (lhs.x * rhs.x + lhs.y * rhs.y);
}

double	vec2f_length(t_vec2f self)
{
	return (sqrt(vec2f_dot(self, self)));
}

t_vec2f	vec2f_normalize(t_vec2f self)
{
	double	length;

	length = vec2f_length(self);
	if (length == 0)
		return (self);
	return (vec2f_div_by(self, length));
}

t_vec2f	vec2f_rotate(t_vec2f self, double angle)
{
	t_vec2f	rotated;

	rotated.x = self.x * cos(angle) - self.y * sin(angle);
	rotated.y = self.x * sin(angle) + self.y * cos(angle);
	return (rotated);
}
