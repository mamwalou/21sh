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
	while (autocmpl->match)
	{
		ft_putstr(autocmpl->match->content);

	}
	win->new_x -= 2;
}

void		aff_auto(t_autocmp *autocmpl, t_win *win)
{
	int		x;
	int		y;

	while (autocmpl->match)
	{
		ft_putstr(autocmpl->match->content);
		if (autocmpl->match->next != NULL)
		{
			win->new_x += 2;
			ft_putstr("  ");
		}
		win->new_x += ft_strlen(autocmpl->match->content);
		autocmpl->match = autocmpl->match->next;
	}

}
