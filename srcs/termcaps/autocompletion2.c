/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 09:29:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 10:58:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"
#include "../../includes/lexer_parser/lexer_parser.h"

void		aff_less(t_autocmp *autocmpl, t_win *win)
{
	int		count;

	count = 0;
	move_cursr(win, M_DOWN, 1);
	while (autocmpl->match)
	{
		ft_putstr(autocmpl->match->content);
		if (autocmpl->match->next != NULL)
			ft_putstr("  ");
		count += ft_strlen(autocmpl->match->content);
		autocmpl->match = autocmpl->match->next;
	}
	move_cursr(win, M_UP, 1);
	if (count > win->x)
		move_cursr(win, M_LEFT, count - (win->x + win->lenght_line));
	else
		move_cursr(win, M_RIGHT, (win->x + win->lenght_line) - count);
}

void		aff_auto(t_autocmp *autocmpl, t_win *win)
{
	if (autocmpl->occurance > 5)
	{
		move_cursr(win, M_DOWN, 1);
		ft_putstr("to much possibilities");
		move_cursr(win, M_UP, 1);
		move_cursr(win, M_RIGHT, win->x + win->lenght_line - 19);
	}
	else
		aff_less(autocmpl, win);
}
