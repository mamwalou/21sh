/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auto_compl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

int			ft_signal(t_win *win, t_llist *e, char *line, t_memory *mem)
{
	ft_putchar('\n');
	kill(mem->father, SIGSTOP);
	prompt(e);
	return (CTRL_C);
}

char		*tabulation(char *line, t_win *win)
{
	move_cursr(win, CDOWN, 1);
	ft_putstr("in");
	tputs(tgetstr("dl", NULL), 1, ft_puts);
	move_cursr(win, CUP, 1);
	move_cursr(win, CRIGHT, win->pos[0] + 1);
	return (line);
}
