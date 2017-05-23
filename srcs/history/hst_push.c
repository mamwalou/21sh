/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 02:33:38 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 20:27:57 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_push(t_memory *sh, char *cmd)
{
	t_hlst	*node;

	node = (t_hlst *)ft_memalloc(sizeof(t_hlst));
	node->cmd = cmd == NULL ? ft_strdup(sh->inp.cmd) : ft_strdup(cmd);
	node->cmdlen = sh->inp.cmdlen;
	if (sh->state == ENCL && sh->hst.tmphead == NULL)
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
