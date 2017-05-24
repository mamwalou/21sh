/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_ctrl_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 09:23:07 by mbourget          #+#    #+#             */
/*   Updated: 2017/04/13 10:43:12 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_ctrl_p(t_memory *sh)
{
	if (sh->state == HGL || !sh->cb.buf)
		return ;
	cb_paste_internal(sh);
}
