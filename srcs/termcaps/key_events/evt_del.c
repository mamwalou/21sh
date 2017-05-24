/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 08:59:07 by mbourget          #+#    #+#             */
/*   Updated: 2017/04/13 10:43:29 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_del(t_memory *sh)
{
	if (sh->state == HGL)
		return ;
	else if (!sh->inp.cbuf[sh->curs.i])
	{
		tc_write("bl");
		return ;
	}
	ft_memmove(&(sh->inp.cbuf[sh->curs.i]), &(sh->inp.cbuf[sh->curs.i + 1]),
		(sh->inp.cbuflen - sh->curs.i));
	tc_write("cd");
	--sh->inp.cbuflen;
	--sh->inp.cmdlen;
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	cbuf_print(sh, true);
	tc_write("ch+", 0, sh->curs.x);
}
