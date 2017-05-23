/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_dpad_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:16:43 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/11 03:54:29 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_dpad_left(t_memory *sh)
{
	if (sh->state == HGL)
		return ;
	if (sh->curs.i - 1 > PROMPT_SIZE)
	{
		evt_dpad_left(sh);
		while (!ft_isalnum(sh->inp.cbuf[sh->curs.i - 1])
			&& sh->curs.i - 1 > PROMPT_SIZE)
			evt_dpad_left(sh);
		while (ft_isalnum(sh->inp.cbuf[sh->curs.i - 1])
			&& sh->curs.i - 1 >= PROMPT_SIZE)
			evt_dpad_left(sh);
	}
}
