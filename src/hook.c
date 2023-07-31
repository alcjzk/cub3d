/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:14:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/31 19:01:06 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "keymap.h"
#include "hook.h"

void	on_destroy(void *state)
{
	state_destroy(state);
	exit(EXIT_SUCCESS);
}

void	key_hook(mlx_key_data_t keydata, void *state)
{
	if (keydata.action == MLX_RELEASE)
		on_keyup(keydata.key, state);
	else
		on_keydown(keydata.key, state);
}

int	on_keyup(t_key key, t_state *state)
{
	if (key == MLX_KEY_ESCAPE)
		on_destroy(state);
	keymap_set_key_state(&state->keymap, key, KEY_STATE_UP);
	return (0);
}

int	on_keydown(t_key key, t_state *state)
{
	keymap_set_key_state(&state->keymap, key, KEY_STATE_DOWN);
	return (0);
}
