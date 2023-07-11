/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:03:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 19:50:20 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC2F_H
# define VEC2F_H

typedef struct s_vec2f
{
	float	x;
	float	y;
}	t_vec2f;

t_vec2f	vec2f_add(t_vec2f lhs, t_vec2f rhs);
t_vec2f	vec2f_sub(t_vec2f lhs, t_vec2f rhs);
t_vec2f	vec2f_mul(t_vec2f lhs, t_vec2f rhs);
t_vec2f	vec2f_div(t_vec2f lhs, t_vec2f rhs);

#endif
