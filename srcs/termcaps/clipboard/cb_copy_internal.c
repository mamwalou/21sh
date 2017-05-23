/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_copy_internal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 03:53:40 by mbourget          #+#    #+#             */
/*   Updated: 2016/11/18 01:21:06 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh21.h"

void	cb_copy_internal(t_main *sh, bool cut)
{
	int				start;
	size_t			size;

	if (sh->cb.buf)
		ft_strdel(&(sh->cb.buf));
	if (sh->curs.i > sh->curs.s_i)
	{
		start = sh->curs.s_i;
		size = sh->curs.i - sh->curs.s_i + 1;
	}
	else
	{
		start = sh->curs.i;
		size = sh->curs.s_i - sh->curs.i + 1;
	}
	sh->cb.buf = ft_strsub(sh->inp.cbuf, start, size);
	sh->cb.len = size;
	if (cut)
		cb_cut_internal(sh, start, size, start + size);
	highlight_cleanup(sh, cut, start);
}
