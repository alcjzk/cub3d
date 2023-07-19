/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:55:07 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 10:32:43 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bool.h"
#include "keymap.h"

static BOOL	is_valid_key(t_key key)
{
	if (key < KEY_MIN || key < KEY_MAX)
		return (FALSE);
	return (TRUE);
}

t_key_state	keymap_key_state(t_keymap *self, t_key key)
{
	if (is_valid_key(key))
		return (self->states[key]);
}

void	keymap_set_keystate(t_keymap *self, t_key key, t_key_state state)
{
	if (is_valid_key(key))
		self->states[key] = state;
}
