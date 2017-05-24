/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 00:39:11 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 21:50:32 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_reset(t_memory *sh)
{
	if (sh->state == HGL)
		highlight_cleanup(sh, false, 0);
	if (sh->hst.browsing)
	{
		sh->hst.browsing = false;
		sh->hst.current = sh->hst.end;
		if (sh->hst.last_cmd)
			ft_strdel(&(sh->hst.last_cmd));
	}
	ft_bzero(sh->inp.cmd, sh->inp.cmdlen);
	ft_putstr(sh->inp.cbuf);
	sh->curs.x = PROMPT_SIZE;
	sh->curs.x_max = sh->curs.win_x - 1;
	sh->curs.y = 0;
	sh->curs.y_max = 0;
	sh->curs.i = PROMPT_SIZE;
	sh->inp.cbuflen = PROMPT_SIZE;
	sh->inp.cmdlen = 0;
	sh->inp.multi_line = false;
}
