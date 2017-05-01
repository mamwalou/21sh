/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_termcaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 13:28:43 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 14:20:35 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

void			dhistory_termcaps(t_win *win)
{
	int			i;

	if (win->pos_history == 1)
		win->pos_history = g_memory.code_history;
	while (win->cursor_line < win->lenght_line + 1)
	{
		move_cursr(win, M_RIGHT, 1);
		win->cursor_line++;
	}
	move_cursr(win, DELETING, win->cursor_line);
	list_lchar(win->hst[win->pos_history], win);
	win->pos_history--;
}

void			history_termcaps(t_win *win)
{
	int			i;

	if (win->pos_history == g_memory.code_history)
		win->pos_history = 1;
	while (win->cursor_line < win->lenght_line)
	{
		move_cursr(win, M_RIGHT, 1);
		win->cursor_line++;
	}
	move_cursr(win, DELETING, win->cursor_line);
	list_lchar(win->hst[win->pos_history], win);
	win->pos_history++;
}
