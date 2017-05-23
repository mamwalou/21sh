/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_printable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 04:56:55 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 17:17:33 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_printable(t_memory *sh)
{
	if (*(sh->inp.rbuf + 1))
	{
		cb_paste_external(sh);
		return ;
	}
	if (sh->curs.i < sh->inp.cbuflen)
		cbuf_insert(sh, *sh->inp.rbuf);
	else
		cbuf_append(sh, *sh->inp.rbuf);
}
