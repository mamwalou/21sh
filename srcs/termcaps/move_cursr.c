/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 13:27:28 by sbeline          ###   ########.fr       */
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
		if (mode == 4)
			tputs(tgetstr("dc", NULL), 1, ft_puts);
	}
}

void			gest_crs(t_win *win)
{
	if (*(unsigned int*)win->buffer == LEFT)
	{
		if (win->cursor_line > 1)
		{
			win->cursor_line--;
			move_cursr(win, 0, 1);
		}
	}
	if (*(unsigned int*)win->buffer == RIGHT)
	{
		if (win->cursor_line <= win->lenght_line)
		{
			win->cursor_line++;
			move_cursr(win, 1, 1);
		}
	}
}
