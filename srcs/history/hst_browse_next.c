/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_browse_next.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 22:55:27 by mbourget          #+#    #+#             */
/*   Updated: 2017/01/14 00:57:38 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_browse_next(t_memory *sh)
{
	if (sh->hst.current->next)
		sh->hst.current = sh->hst.current->next;
	else
		sh->hst.browsing = false;
	hst_update_cbuf(sh);
}
