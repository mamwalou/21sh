/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_browse_prev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 22:44:18 by mbourget          #+#    #+#             */
/*   Updated: 2017/01/15 00:00:05 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_browse_prev(t_memory *sh)
{
	if (!sh->hst.browsing)
	{
		sh->hst.browsing = true;
		if (sh->inp.cmdlen > 0)
		{
			sh->hst.last_cmd = ft_strdup(sh->inp.cmd);
			sh->hst.last_cmdlen = sh->inp.cmdlen;
		}
	}
	else if (sh->hst.current->prev)
		sh->hst.current = sh->hst.current->prev;
	else
		return ;
	hst_update_cbuf(sh);
}
