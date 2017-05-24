/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_dpad_right.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:12:47 by mbourget          #+#    #+#             */
/*   Updated: 2016/11/12 08:56:17 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_dpad_right(t_memory *sh)
{
	if (sh->state == HGL)
	{
		if (sh->curs.i + 1 >= sh->inp.cbuflen)
			return ;
		++sh->curs.i;
		highlight(sh);
		return ;
	}
	if (sh->curs.i == sh->inp.cbuflen && sh->curs.y == sh->curs.y_max)
		return ;
	++sh->curs.i;
	if (sh->curs.x < sh->curs.x_max)
	{
		++sh->curs.x;
		tc_write("ch+", 0, sh->curs.x);
	}
	else if (sh->curs.x >= sh->curs.x_max)
	{
		sh->curs.x = 0;
		++sh->curs.y;
		tc_write("do");
	}
}
