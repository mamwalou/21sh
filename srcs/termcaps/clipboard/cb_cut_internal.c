/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_cut_internal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 04:00:16 by mbourget          #+#    #+#             */
/*   Updated: 2017/01/12 00:46:40 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	cb_cut_internal(t_main *sh, int start, size_t size, size_t total)
{
	unsigned int	y;
	size_t			rest;

	if (sh->inp.cbuf[total])
	{
		rest = sh->inp.cbuflen - total;
		ft_memmove(&(sh->inp.cbuf[start]), &(sh->inp.cbuf[total]), rest);
		ft_bzero(&(sh->inp.cbuf[start + rest]), size);
	}
	else
		ft_bzero(&(sh->inp.cbuf[start]), total);
	sh->inp.cbuflen -= size;
	sh->inp.cmdlen -= size;
	sh->curs.x = start % sh->curs.win_x;
	y = start / sh->curs.win_x;
	if (sh->curs.y > y)
	{
		tc_write("UP+", 0, sh->curs.y - y);
		sh->curs.y = y;
	}
	sh->curs.y_max = sh->inp.cbuflen / sh->curs.win_x;
}
