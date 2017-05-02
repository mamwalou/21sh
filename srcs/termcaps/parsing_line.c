/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 10:49:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#define MAX_LEN 2024

void		read_display(t_win *win)
{
	int		z;
	int		y;

	z = 0;
	while (y != 4 || (y != 0 && z != 0))
	{
		ft_bzero(win->buffer, MAX_LEN + 1);
		read(0, win->buffer, MAX_LEN);
		if (win->buffer[0])
			;
		z = (win->buffer[0]) ? 1 : 0;
	}
}

int			my_ctrl(int test)
{
	if (test == '-'
		|| test == ';'
		|| test == '<'
		|| test == '>'
		|| test == '&'
		|| test == '='
		|| test == '/'
		|| test == '.'
		|| test == '|'
		|| test == '"'
		|| test == '$'
		|| test == '~'
		|| test == '_'
		|| test == 92
		|| test == 96
		|| test == 39
		|| test == ' '
		|| test == '!')
		return (1);
	return (0);
}
