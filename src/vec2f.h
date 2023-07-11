/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:03:55 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 19:05:32 by tjaasalo         ###   ########.fr       */
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

#endif
