/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_tmp_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 09:08:02 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/24 09:12:02 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_tmp_push(t_memory *sh)
{
	t_hlst	*node;

	node = (t_hlst *)ft_memalloc(sizeof(t_hlst));
	node->cmd = ft_strdup(sh->inp.cmd);
	node->cmdlen = sh->inp.cmdlen;
	if (sh->hst.tmphead == NULL)
		sh->hst.tmphead = node;
	if (!sh->hst.head)
		sh->hst.head = node;
	else
	{
		sh->hst.current = sh->hst.end;
		node->prev = sh->hst.current;
		sh->hst.current->next = node;
	}
	sh->hst.current = node;
	sh->hst.end = node;
}
