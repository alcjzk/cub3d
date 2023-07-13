/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:00:52 by emajuri           #+#    #+#             */
/*   Updated: 2023/07/13 14:03:45 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

typedef struct s_line
{
	int		line_height;
	int		start;
	int		end;
	t_color	color;
}	t_line;