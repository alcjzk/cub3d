/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:54:48 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/19 10:31:46 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYMAP_H
# define KEYMAP_H

# define KEY_MAX 126
# define KEY_MIN 0

typedef enum e_key
{
	KEY_W = 13,
	KEY_A = 0,
	KEY_S = 1,
	KEY_D = 2,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_ESC = 54
}	t_key;

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
