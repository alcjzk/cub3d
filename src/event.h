/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:04:20 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/07/04 17:45:14 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

typedef struct s_state	t_state;

typedef enum e_eventkind
{
	EVENT_KEYDOWN = 2,
	EVENT_KEYUP = 3,
	EVENT_DESTROY = 17,
	EVENT_EXPOSE = 12
}	t_eventkind;

typedef struct s_event
{
	t_eventkind		kind;
	t_state			*state;
	int				keycode;
}	t_event;

#endif
