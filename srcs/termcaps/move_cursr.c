/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

int				init_varfcurs(void)
{
	if (!(g_clear = tgetstr("cl", NULL))
		|| !(g_up = tgetstr("up", NULL))
		|| !(g_down = tgetstr("do", NULL))
		|| !(g_right = tgetstr("nd", NULL))
		|| !(g_left = tgetstr("le", NULL)))
		return (-1);
	return (1);
}

void			move_cursr(t_win *win, int mode, int iteration)
{
	if (mode == CUP)
	{
		while (iteration-- != 0)
			tputs(g_up, 1, ft_puts);
	}
	if (mode == CDOWN)
	{
		while (iteration-- != 0)
			tputs(g_down, 1, ft_puts);
	}
	if (mode == CLEFT)
	{
		while (iteration-- != 0)
			tputs(g_left, 1, ft_puts);
	}
	if (mode == CRIGHT)
	{
		while (iteration-- != 0)
			tputs(g_right, 1, ft_puts);
	}
}
