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
	win->y++;
	win->new_x = 0;
	while (autocmpl->match)
	{
		ft_putstr(autocmpl->match->content);
		if (autocmpl->match->next != NULL)
			ft_putstr("  ");
		win->new_x += ft_strlen(autocmpl->match->content) + 2;
		autocmpl->match = autocmpl->match->next;
	}
}

void		aff_auto(t_autocmp *autocmpl, t_win *win)
{
	win->new_x = 0;
	if (autocmpl->occurance > 5)
	{
		move_cursr(win, M_DOWN, 1);
		win->y++;
		ft_putstr("to much possibilities");
		win->new_x += 21;
	}
	else
		aff_less(autocmpl, win);
}
