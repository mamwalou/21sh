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

void				auto_push(char *str, t_win *win, int pos)
{
	while (str[pos])
	{
		push_line(win, str[pos]);
		pos++;
	}
}

void		aff_auto(t_autocmp *autocmpl, t_win *win)
{
	int		count;
	t_llist	*ptr;

	count = 0;
	ptr = autocmpl->match;
	move_cursr(win, M_DOWN, 1);
	while (ptr)
	{
		ft_putstr(ptr->content);
		if (ptr->next != NULL)
			ft_putstr("  ");
		if (count >= g_term.apt.ws_row)
		{
			move_cursr(win, M_DOWN, 1);
			count = 0;
		}
		count += ft_strlen(autocmpl->match->content);
		ptr = ptr->next;
	}
	move_cursr(win, M_DOWN, 1);
	prompt();
	printline(win->begin);
}
