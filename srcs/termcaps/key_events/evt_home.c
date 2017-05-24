/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:32:01 by mbourget          #+#    #+#             */
/*   Updated: 2016/11/15 05:06:35 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_home(t_memory *sh)
{
	if (sh->curs.i == PROMPT_SIZE)
		return ;
	else if (sh->state == HGL)
	{
		sh->curs.i = PROMPT_SIZE;
		highlight(sh);
		return ;
	}
	sh->curs.i = PROMPT_SIZE;
	sh->curs.x = PROMPT_SIZE;
	if (sh->curs.y > 0)
	{
		tc_write("UP+", 0, sh->curs.y);
		sh->curs.y = 0;
	}
	tc_write("ch+", 0, PROMPT_SIZE);
}
