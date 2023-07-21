/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:21:43 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/21 14:56:39 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec2f.h"
# include "view.h"

typedef enum e_side
{
	EW,
	NS
}	t_side;

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

void	ray_init(t_ray *self, t_scene *scene);
void	ray_cast(t_ray *self, t_scene *scene);

#endif