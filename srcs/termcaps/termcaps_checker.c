/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

static const t_terminal	g_tableau[CNT_TERM] =
{
	{DELETE, ft_del},
	{SPACE, ft_space},
	{CTRL_L, ft_clear},
	{CTRL_C, ft_signal},
	{TAB, ft_search},
};

int						ft_space(t_win *w, t_llist *e, char *line, t_memory *m)
{
	ft_putchar(' ');
	return (SPACE);
}

int						ft_puts(int c)
{
	write(1, &c, 1);
	return (0);
}

int						ft_clear(t_win *w, t_llist *e, char *line, t_memory *m)
{
	tputs(g_clear, 1, ft_puts);
	prompt(e);
	if (line)
		ft_putstr(line);
	return (CTRL_L);
}

int						ft_del(t_win *win, t_llist *e, char *line, t_memory *m)
{
	if (win->lineshell > 0)
	{
		win->lineshell--;
		move_cursr(win, CLEFT, 1);
		ft_putchar(' ');
		move_cursr(win, CLEFT, 1);
	}
	return (DELETE);
}

int						termc_ctrl(char *l, t_win *w, t_llist *e, t_memory *m)
{
	int		i;
	int		ret;

	i = 0;
	while (i < CNT_TERM)
	{
		if (g_tableau[i].input == w->buffer[0])
		{
			if ((ret = g_tableau[i].f(w, e, l, m)) == TAB)
				m->c_t_r = ret;
			return (ret);
		}
		i++;
	}
	return (0);
}
