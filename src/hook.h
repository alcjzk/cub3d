/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:17:32 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 10:34:52 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "state.h"

int	on_destroy(t_state *state);
int	on_keyup(int keycode, t_state *state);
int	on_keydown(t_key key, t_state *state);

#endif
