/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:14:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 10:34:47 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "keymap.h"
#include "hook.h"

int	on_destroy(t_state *state)
{
	state_destroy(state);
	exit(EXIT_SUCCESS);	
}

int	on_keyup(t_key key, t_state *state)
{
	if (key == KEY_ESC)
		return (on_destroy(state));
	keymap_set_keystate(&state->keymap, key, KEY_STATE_UP);
	return (0);
}

int	on_keydown(t_key key, t_state *state)
{
	keymap_set_keystate(&state->keymap, key, KEY_STATE_DOWN);
	return (0);
}
