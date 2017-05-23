/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_dpad_up.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:12:47 by mbourget          #+#    #+#             */
/*   Updated: 2017/04/13 10:40:22 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_dpad_up(t_memory *sh)
{
	if (sh->state == HGL || sh->curs.y == 0)
		return ;
	--sh->curs.y;
	tc_write("up");
	if ((sh->curs.y * sh->curs.win_x) + sh->curs.x < PROMPT_SIZE)
	{
		sh->curs.i = PROMPT_SIZE;
		sh->curs.x = PROMPT_SIZE;
		tc_write("ch+", 0, sh->curs.x);
	}
	else
		sh->curs.i -= sh->curs.win_x;
}
