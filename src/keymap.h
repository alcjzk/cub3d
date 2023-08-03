/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:54:48 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/08/03 19:28:47 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

# define KEY_MAX 348
# define KEY_MIN 0

# include "MLX42.h"

typedef keys_t t_key;

typedef enum e_key_state
{
	KEY_STATE_UP,
	KEY_STATE_DOWN
}	t_key_state;

typedef struct s_keymap
{
	t_key_state	states[KEY_MAX + 1];
}	t_keymap;

t_key_state	keymap_key_state(t_keymap *self, t_key key);
void		keymap_set_key_state(t_keymap *self, t_key key, t_key_state state);

#endif
