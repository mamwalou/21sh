/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_dpad_down.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:12:47 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 20:16:57 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_dpad_down(t_memory *sh)
{
	if (sh->state == HGL)
	{
		if (sh->curs.i + sh->curs.win_x < sh->inp.cbuflen)
			sh->curs.i += sh->curs.win_x;
		else if (sh->curs.i < sh->inp.cbuflen - 1)
			sh->curs.i = sh->inp.cbuflen - 1;
		else
			return ;
		highlight(sh);
		return ;
	}
	else if (sh->state == IDLE && sh->hst.browsing)
		hst_browse_next(sh);
}
