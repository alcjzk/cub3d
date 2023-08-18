/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_print_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:21:41 by emajuri           #+#    #+#             */
/*   Updated: 2023/08/18 15:59:37 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "libft.h"

void	scene_print_error(t_scene *self)
{
	ft_putstr_fd("Error\n", 2);
	if (!self->north_texture_path)
		ft_putstr_fd("North_texture_path is misconfigured\n", 2);
	else if (!self->south_texture_path)
		ft_putstr_fd("South_texture_path is misconfigured\n", 2);
	else if (!self->west_texture_path)
		ft_putstr_fd("West_texture_path is misconfigured\n", 2);
	else if (!self->east_texture_path)
		ft_putstr_fd("East_texture_path is misconfigured\n", 2);
	else if (!self->set_floor_color)
		ft_putstr_fd("Floor_color is misconfigured\n", 2);
	else if (!self->set_ceiling_color)
		ft_putstr_fd("Ceiling_color is misconfigured\n", 2);
	else if (!self->map.is_valid)
		ft_putstr_fd("Map is misconfigured\n", 2);
}