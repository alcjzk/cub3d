/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:17:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/08/03 19:29:42 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "state.h"

void	on_destroy(t_state *state);
void	key_hook(mlx_key_data_t keydata, t_state *state);
void	on_keyup(t_key key, t_state *state);
void	on_keydown(t_key key, t_state *state);

#endif
