/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_h.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 08:02:34 by mbourget          #+#    #+#             */
/*   Updated: 2017/04/13 10:42:40 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_h(t_memory *sh)
{
	if (sh->state != HGL && sh->curs.i >= sh->inp.cbuflen)
		return ;
	else if (sh->state == HGL)
	{
		highlight_cleanup(sh, false, 0);
		return ;
	}
	sh->state = HGL;
	tc_write("sc");
	tc_write("vi");
	sh->curs.s_i = sh->curs.i;
	highlight(sh);
}
