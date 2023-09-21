/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmtblock.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjaasalo <tjaasalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:11:41 by tjaasalo          #+#    #+#             */
/*   Updated: 2023/09/19 17:14:11 by tjaasalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMTBLOCK_H
# define FMTBLOCK_H

# include <stdlib.h>
# include "bool.h"

typedef struct s_fmtblock
{
	char	*p;
	_Bool	dynamic;
	size_t	len;
	void	*next;
}	t_fmtblock;

t_fmtblock	*fmtblock_new(char *p, size_t len, _Bool dynamic);
int			fmtblock_write_all(t_fmtblock *list, int fd);
void		*fmtblock_free_all(t_fmtblock *list);

#endif
