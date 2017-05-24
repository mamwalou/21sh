/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   highlight_cleanup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 04:37:08 by mbourget          #+#    #+#             */
/*   Updated: 2017/04/13 10:39:02 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	highlight_cleanup(t_memory *sh, bool cut, int start)
{
	if (sh->curs.y > 0)
		tc_write("UP+", 0, sh->curs.y);
	tc_write("ch+", 0, PROMPT_SIZE);
	sh->curs.i = PROMPT_SIZE;
	tc_write("cd");
	cbuf_print(sh, false);
	if (cut)
	{
		sh->curs.i = start;
		tc_write("ch+", 0, sh->curs.x);
	}
	else
	{
		sh->curs.i = sh->curs.s_i;
		tc_write("rc");
	}
	tc_write("ve");
	sh->state = IDLE;
}
