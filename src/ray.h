/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 13:21:43 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/18 16:58:58 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec2f.h"
# include "view.h"

typedef enum e_side
{
	horizontal,
	vertical
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

void	calc_deltadistance(t_player *player, t_ray *ray);
void	calc_steps(t_player *player, t_ray *ray);
void	dda(t_scene *scene, t_ray *ray);

#endif