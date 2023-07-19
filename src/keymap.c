/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:55:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 10:17:21 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keymap.h"

static BOOL	is_valid_key(t_key key)
{
	if (key < KEY_MIN || key < KEY_MAX)
		return (FALSE);
	return (TRUE);
}

BOOL	keymap_is_down(t_keymap *self, t_key key)
{
	if (is_valid_key(key))
		return (self->is_down[key]);
}

void	keymap_set_keystate(t_keymap *self, t_key key, BOOL is_down)
{
	if (is_valid_key(key))
		self->is_down[key] = is_down;
}
