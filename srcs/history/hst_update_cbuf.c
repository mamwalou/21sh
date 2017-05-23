/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_update_cbuf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:38:14 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 20:14:48 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_update_cbuf(t_memory *sh)
{
	ft_bzero(sh->inp.cmd, sh->inp.cmdlen);
	evt_home(sh);
	tc_write("cd");
	if (sh->hst.browsing)
	{
		sh->inp.cmdlen = sh->hst.current->cmdlen;
		ft_memcpy(sh->inp.cmd, sh->hst.current->cmd, sh->inp.cmdlen);
	}
	else if (sh->hst.last_cmd)
	{
		sh->inp.cmdlen = sh->hst.last_cmdlen;
		ft_memcpy(sh->inp.cmd, sh->hst.last_cmd, sh->inp.cmdlen);
		ft_strdel(&(sh->hst.last_cmd));
	}
	else
		sh->inp.cmdlen = 0;
	sh->inp.cbuflen = sh->inp.cmdlen + PROMPT_SIZE;
	sh->curs.i = sh->inp.cbuflen;
	sh->curs.x = sh->curs.i % sh->curs.win_x;
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
	sh->curs.y = sh->curs.y_max;
	ft_putstr(sh->inp.cmd);
	if (sh->curs.x == 0)
		tc_write("do");
}
