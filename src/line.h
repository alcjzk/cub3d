/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:00:52 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/18 16:50:35 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include "color.h"
# include "view.h"

typedef struct s_line
{
	int		height;
	int		start;
	int		end;
	t_color	color;
}	t_line;

void	draw_line(t_view *self, t_scene *scene, int x);

#endif