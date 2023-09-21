/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_textures_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/21 17:04:56 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "scene.h"
# include "libft.h"
# include "bool.h"

_Bool	scene_set_door(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;

	if (self->texture_options.door)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Found duplicate door identifier\n", 2);
		return (FALSE);
	}
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.door = dup;
	return (TRUE);
}

_Bool	scene_set_sprite(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;

	if (self->texture_options.sprite)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Found duplicate sprite identifier\n", 2);
		return (FALSE);
	}
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.sprite = dup;
	return (TRUE);
}

#endif
