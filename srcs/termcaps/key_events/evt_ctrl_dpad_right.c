/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_dpad_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:12:47 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/11 03:44:39 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_dpad_right(t_memory *sh)
{
	if (sh->state == HGL)
		return ;
	while (!ft_isalnum(sh->inp.cbuf[sh->curs.i])
		&& sh->curs.i < sh->inp.cbuflen)
		evt_dpad_right(sh);
	while (ft_isalnum(sh->inp.cbuf[sh->curs.i]) && sh->curs.i < sh->inp.cbuflen)
		evt_dpad_right(sh);
}
