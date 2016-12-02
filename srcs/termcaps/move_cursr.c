/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/12/01 15:27:35 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

void			move_cursr(t_win *win, int mode, int iteration)
{
	while (iteration-- > 0)
	{
		if (mode == 0)
			tputs(tgetstr("le", NULL), 1, ft_puts);
		if (mode == 1)
			tputs(tgetstr("nd", NULL), 1, ft_puts);
		if (mode == 2)
			tputs(tgetstr("up", NULL), 1, ft_puts);
		if (mode == 3)
			tputs(tgetstr("do", NULL), 1, ft_puts);
	}
}

int 			gest_crs(t_line *begin, t_line *end, t_win *win)
{
	if (*(unsigned int*)win->buffer == LEFT)
	{
		if (win->mov_line > 1)
		{
			win->mov_line--;
			move_cursr(win, 0, 1);
		}
	}
	if (*(unsigned int*)win->buffer == RIGHT)
	{
		if (win->mov_line <= win->pos_line)
		{
			win->mov_line++;
			move_cursr(win, 1, 1);
		}
	}
	return (0);
}
