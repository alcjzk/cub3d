/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:05:36 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/11 19:06:38 by tjaasalo         ###   ########.fr       */
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
