/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:03:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/23 15:12:49 by tjaasalo         ###   ########.fr       */
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
t_vec2f	vec2f_div_by(t_vec2f lhs, float rhs);
float	vec2f_dot(t_vec2f lhs, t_vec2f rhs);
double	vec2f_length(t_vec2f self);
t_vec2f	vec2f_normalize(t_vec2f self);

#endif
