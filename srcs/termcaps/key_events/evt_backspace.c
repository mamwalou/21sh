/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_backspace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:10:41 by mbourget          #+#    #+#             */
/*   Updated: 2017/04/13 10:39:19 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_backspace(t_memory *sh)
{
	if (sh->state == HGL)
	{
		cb_copy_internal(sh, true);
		return ;
	}
	else if (sh->curs.i == PROMPT_SIZE)
	{
		tc_write("bl");
		return ;
	}
	ft_memmove(&(sh->inp.cbuf[sh->curs.i - 1]), &(sh->inp.cbuf[sh->curs.i]),
		(sh->inp.cbuflen - sh->curs.i));
	sh->inp.cbuf[sh->inp.cbuflen - 1] = 0;
	evt_dpad_left(sh);
	tc_write("cd");
	--sh->inp.cbuflen;
	--sh->inp.cmdlen;
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	cbuf_print(sh, true);
	tc_write("ch+", 0, sh->curs.x);
}
