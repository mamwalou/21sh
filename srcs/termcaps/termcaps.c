/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 12:41:05 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "shell.h"

void	termcaps(t_memory *sh)
{
	int		ret;

	while ((ret = read(STDIN_FILENO, sh->inp.rbuf, RBUF_SIZE)) > 0)
	{
		sh->signo ? sig_handler(sh) : evt_handler(sh);
		ft_bzero(sh->inp.rbuf, sizeof(sh->inp.rbuf));
		if (sh->inp.ready)
		{
			sh->line = sh->inp.cmd;
			sh->line_lenght = sh->inp.cmdlen;
			sh->inp.ready = false;
			break ;
		}
	}
}
