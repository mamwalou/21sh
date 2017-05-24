/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_dpad_down.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:12:47 by mbourget          #+#    #+#             */
/*   Updated: 2017/04/13 10:39:43 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_dpad_down(t_memory *sh)
{
	if (sh->state == HGL || sh->curs.y == sh->curs.y_max)
		return ;
	++sh->curs.y;
	tc_write("do");
	if ((sh->curs.y * sh->curs.win_x) + sh->curs.x > sh->inp.cbuflen)
	{
		sh->curs.i = sh->inp.cbuflen;
		sh->curs.x = sh->curs.i % sh->curs.win_x;
	}
	else
		sh->curs.i += sh->curs.win_x;
	tc_write("ch+", 0, sh->curs.x);
}
