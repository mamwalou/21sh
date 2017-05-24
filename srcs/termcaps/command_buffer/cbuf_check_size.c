/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbuf_check_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 06:41:45 by mbourget          #+#    #+#             */
/*   Updated: 2017/01/12 01:59:48 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	cbuf_check_size(t_memory *sh, size_t len)
{
	char	*cbuf;

	if ((sh->inp.cbuflen + len) < sh->inp.maxlen)
		return ;
	while ((sh->inp.cbuflen + len) >= sh->inp.maxlen)
		sh->inp.maxlen += 1024;
	cbuf = (char *)ft_memalloc(sh->inp.maxlen);
	ft_memcpy(cbuf, sh->inp.cbuf, sh->inp.cbuflen);
	free(sh->inp.cbuf);
	sh->inp.cbuf = cbuf;
	sh->inp.cmd = &(cbuf[PROMPT_SIZE]);
}
