/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_set_textures_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:02:16 by emajuri           #+#    #+#             */
/*   Updated: 2023/09/17 14:29:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef BONUS_FEATURES

# include "scene.h"
# include "libft.h"

BOOL	scene_set_door(t_scene *self, char *line)
{
	char	*dup;
	size_t	i;

	if (self->texture_options.door)
		return (FALSE);
	i = 2;
	while (ft_isspace(line[i]))
		i++;
	dup = ft_strdup(&line[i]);
	if (!dup)
		return (FALSE);
	self->texture_options.door = dup;
	return (TRUE);
}

#endif
