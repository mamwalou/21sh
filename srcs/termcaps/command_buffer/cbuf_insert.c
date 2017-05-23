/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:51:13 by mbourget          #+#    #+#             */
/*   Updated: 2017/01/12 01:57:51 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_insert(t_memory *sh, char inp)
{
	cbuf_check_size(sh, 1);
	ft_memmove(&(sh->inp.cbuf[sh->curs.i + 1]), &(sh->inp.cbuf[sh->curs.i]),
		(sh->inp.cbuflen - sh->curs.i));
	sh->inp.cbuf[sh->curs.i] = inp;
	tc_write("cd");
	++sh->inp.cbuflen;
	++sh->inp.cmdlen;
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	cbuf_print(sh, false);
	evt_dpad_right(sh);
}
