/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_termcaps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 13:28:43 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/18 18:54:11 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

int				dhistory_termcaps(t_win *win)
{
	int			i;

	if (!search_env(g_env, "HISTORY="))
		return (1);
	while (win->cursor_line < win->lenght_line + 1)
	{
		move_cursr(win, M_RIGHT, 1);
		win->cursor_line++;
	}
	move_cursr(win, DELETING, win->cursor_line);
	list_lchar(win->hst[win->pos_history], win);
	if (win->pos_history == 0)
		win->pos_history = g_memory.code_history - 1;
	else
		win->pos_history--;
	return (1);
}

int				history_termcaps(t_win *win)
{
	int			i;

	if (!search_env(g_env, "HISTORY="))
		return (1);
	if (win->pos_history + 1 == g_memory.code_history)
		win->pos_history = 0;
	else
		win->pos_history++;
	while (win->cursor_line < win->lenght_line + 1)
	{
		win->cursor_line++;
		move_cursr(win, M_RIGHT, 1);
	}
	move_cursr(win, DELETING, win->cursor_line);
	list_lchar(win->hst[win->pos_history], win);
	return (1);
}
