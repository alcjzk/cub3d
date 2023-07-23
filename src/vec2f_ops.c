/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:05:36 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/23 15:05:57 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2f.h"

t_vec2f	vec2f_add(t_vec2f lhs, t_vec2f rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return (lhs);
}

t_vec2f	vec2f_sub(t_vec2f lhs, t_vec2f rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return (lhs);
}

t_vec2f	vec2f_mul(t_vec2f lhs, t_vec2f rhs)
{
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
	return (lhs);
}

t_vec2f	vec2f_div(t_vec2f lhs, t_vec2f rhs)
{
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;
	return (lhs);
}

t_vec2f	vec2f_div_by(t_vec2f lhs, float rhs)
{
	lhs.x /= rhs;
	lhs.y /= rhs;
	return (lhs);
}
