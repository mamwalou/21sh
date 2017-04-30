/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   depush_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 17:31:36 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 15:39:33 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

static void		limit_depush(t_win *win)
{
	t_line		*save;
	t_line		*dsave;
	int			i;

	if (win->cursor_line - 1 == win->lenght_line)
	{
		save = win->end->prev;
		free(win->end);
		win->end = save;
		win->end->next = NULL;
	}
	else
	{
		i = 0;
		save = win->begin;
		while (++i < win->cursor_line - 1)
			save = save->next;
		dsave = save;
		save->prev->next = save->next;
		save->next->prev = save->prev;
		free(dsave);
	}
}

void			depushline(t_win *win)
{
	if (win->cursor_line == 1)
		return ;
	if (win->lenght_line == 1)
	{
		free((win->begin));
		win->begin = NULL;
		win->end = NULL;
	}
	else
		limit_depush(win);
	win->lenght_line--;
	win->cursor_line--;
	move_cursr(win, M_LEFT, 1);
	move_cursr(win, M_DEL, 1);
}
