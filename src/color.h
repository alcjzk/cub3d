/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:53:37 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/01 17:36:01 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color_rgba
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}	t_color_rgba;

typedef union u_color
{
	int				value;
	t_color_rgba	channels;
}	t_color;

#endif
