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

static const t_input	g_tableau[CNT_TERM - 2] =
{
	{DELETE, ft_del},
	{CTRL_L, ft_clear},
	{TAB, ft_search},
};

int						ft_space(t_win *w, t_llist *e, char *line, t_memory *m)
{
	return (SPACE);
}

int						ft_puts(int c)
{
	return (0);
}

int						ft_clear(t_win *w, t_llist *e, char *line, t_memory *m)
{

	return (CTRL_L);
}

int						ft_del(t_win *win, t_llist *e, char *line, t_memory *m)
{
	depushline(line, win);
	ft_putstr(line);
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
