/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emajuri <emajuri@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:17:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/31 19:01:45 by emajuri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "state.h"

void	on_destroy(void *state);
void	key_hook(mlx_key_data_t keydata, void *state);
int		on_keyup(t_key key, t_state *state);
int		on_keydown(t_key key, t_state *state);

#endif
