/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:14:21 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/04 17:54:12 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "hook.h"

int	on_destroy(t_state *state)
{
	state_destroy(state);
	exit(EXIT_SUCCESS);	
}

int	on_keyup(int keycode, t_state *state)
{
	if (keycode == 53)
		return (on_destroy(state));
	return (0);
}
