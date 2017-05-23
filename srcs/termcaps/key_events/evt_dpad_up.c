/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_dpad_up.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:12:47 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 17:15:11 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_dpad_up(t_memory *sh)
{
	if (sh->state == HGL)
	{
		if (sh->curs.i > sh->curs.x_max
			&& (sh->curs.i - sh->curs.win_x) > PROMPT_SIZE)
			sh->curs.i -= sh->curs.win_x;
		else if (sh->curs.i > PROMPT_SIZE)
			sh->curs.i = PROMPT_SIZE;
		else
			return ;
		highlight(sh);
	}
	else if (sh->state == IDLE) //&& sh->hst.head)
		; //hst_browse_prev(sh);
}
