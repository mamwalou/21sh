/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 13:36:51 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"
#define NB_INPUT 6

static const t_input		g_input[NB_INPUT] =
{
	{DELETE, depushline},
	{TAB, autocompletion},
	{LEFT, gest_crs},
	{RIGHT, gest_crs},
	{UP, history_termcaps},
	{DOWN, dhistory_termcaps},
};

int			ft_puts(int c)
{
	write(1, &c, 1);
	return (0);
}

void			input(t_win *win)
{
	int						count;

	count = 0;
	while (count < NB_INPUT &&
		g_input[count].input != *(unsigned int*)win->buffer)
		count++;
	if (count != NB_INPUT)
		g_input[count].f(win);
}
