/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cb_paste_external.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 04:54:44 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 17:54:04 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static void	print_read_buffer(t_memory *sh, void (*f)(t_memory *, char))
{
	int	i;

	i = -1;
	while (sh->inp.rbuf[++i])
		ft_isprint(sh->inp.rbuf[i]) ? f(sh, sh->inp.rbuf[i]) : f(sh, ' ');
	ft_bzero(sh->inp.rbuf, sizeof(sh->inp.rbuf));
}

void		cb_paste_external(t_memory *sh)
{
	int		ret;
	void	(*f)(t_memory *, char);

	if (sh->curs.i < sh->inp.cbuflen)
		f = &cbuf_insert;
	else
		f = &cbuf_append;
	print_read_buffer(sh, f);
	tc_set_timed_read(sh);
	ret = RBUF_SIZE;
	while ((ret = read(STDIN_FILENO, sh->inp.rbuf, RBUF_SIZE)) > 0)
		print_read_buffer(sh, f);
	tc_set_blocking_read(sh);
}
