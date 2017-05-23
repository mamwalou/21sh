/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_newline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 04:17:20 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 17:07:27 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void			evt_newline(t_memory *sh)
{
	if (sh->state == HGL)
	{
		cb_copy_internal(sh, false);
		return ;
	}
	sh->inp.ready = true;
	// ft_putchar('\n');
	// cbuf_reset(sh);
}
