/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:21:43 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/13 14:00:30 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec2f.h"

typedef enum e_side
{
	horizontal,
	vertical
} t_side;

typedef struct s_ray
{
	t_vec2f		delta_dist;
	t_vec2f		side_dist;
	t_vec2f		map_pos;
	t_vec2f		step;
	float		perp_wall_dist;
	t_side		hit;
	int			side;
}	t_ray;

#endif