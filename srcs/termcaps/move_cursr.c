/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/12 14:39:17 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

void			move_cursr(t_win *win, t_iter iter, int iteration)
{
	while (iteration-- > 0)
	{
		if (iter == M_LEFT)
			tputs(tgetstr("le", NULL), 1, ft_puts);
		if (iter == M_RIGHT)
			tputs(tgetstr("nd", NULL), 1, ft_puts);
		if (iter == M_UP)
			tputs(tgetstr("up", NULL), 1, ft_puts);
		if (iter == M_DOWN)
			tputs(tgetstr("do", NULL), 1, ft_puts);
		if (iter == M_DEL)
			tputs(tgetstr("dc", NULL), 1, ft_puts);
		if (iter == DELETING)
			depushline(win);
		if (iter == PUSH)
			depushline(win);
	}
}

int				gest_crs(t_win *win)
{
	if (*(unsigned int*)win->buffer == LEFT)
	{
		if (win->cursor_line > 1)
		{
			win->cursor_line--;
			move_cursr(win, M_LEFT, 1);
		}
	}
	if (*(unsigned int*)win->buffer == RIGHT)
	{
		if (win->cursor_line <= win->lenght_line)
		{
			win->cursor_line++;
			move_cursr(win, M_RIGHT, 1);
		}
	}
	return (1);
}
