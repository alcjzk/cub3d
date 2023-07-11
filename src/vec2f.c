/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:05:36 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 19:50:12 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec2f.h"

t_vec2f	vec2f_add(t_vec2f lhs, t_vec2f rhs)
{
	t_vec2f	out;

	out.x = lhs.x + rhs.x;
	out.y = lhs.y + rhs.y;
	return (out);
}

t_vec2f	vec2f_sub(t_vec2f lhs, t_vec2f rhs)
{
	t_vec2f	out;

	out.x = lhs.x - rhs.x;
	out.y = lhs.y - rhs.y;
	return (out);
}

t_vec2f	vec2f_mul(t_vec2f lhs, t_vec2f rhs)
{
	t_vec2f	out;

	out.x = lhs.x * rhs.x;
	out.y = lhs.y * rhs.y;
	return (out);
}

t_vec2f	vec2f_div(t_vec2f lhs, t_vec2f rhs)
{
	t_vec2f	out;

	out.x = lhs.x / rhs.x;
	out.y = lhs.y / rhs.y;
	return (out);
}