/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_append.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 23:51:14 by mbourget          #+#    #+#             */
/*   Updated: 2017/01/12 01:57:44 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_append(t_memory *sh, char inp)
{
	cbuf_check_size(sh, 1);
	ft_putchar(inp);
	sh->inp.cbuf[sh->curs.i] = inp;
	++sh->inp.cbuflen;
	++sh->inp.cmdlen;
	++sh->curs.x;
	++sh->curs.i;
	if (sh->curs.x > sh->curs.x_max)
	{
		tc_write("do");
		sh->curs.x = 0;
		++sh->curs.y;
		sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	}
}
