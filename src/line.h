/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:00:52 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/19 15:07:21 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "color.h"
# include "view.h"
# include "ray.h"

typedef struct s_line
{
	int		height;
	int		start;
	int		end;
	t_color	color;
}	t_line;

void	line_init(t_line *self, t_ray *ray);
void	line_draw_color(t_view *view, t_line *self, int x, t_ray *ray);

#endif