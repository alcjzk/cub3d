/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:14:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 10:02:05 by tjaasalo         ###   ########.fr       */
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

int	on_keyup(int keycode, t_state *state)
{
	if (keycode == KEY_ESC)
		return (on_destroy(state));
	return (0);
}
