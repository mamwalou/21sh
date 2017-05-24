/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evt_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 06:22:34 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/24 10:46:18 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	evt_handler(t_memory *sh)
{
	int			i;
	static void (*fptrs[])(t_memory *) = { &evt_ctrl_d, &evt_ctrl_h,
		&evt_newline, &evt_ctrl_p, &evt_backspace, &evt_dpad_up,
		&evt_dpad_down, &evt_dpad_right, &evt_dpad_left, &evt_end, &evt_home,
		&evt_del, &evt_ctrl_dpad_up, &evt_ctrl_dpad_down, &evt_ctrl_dpad_right,
		&evt_ctrl_dpad_left, NULL };
	static char	*keys[] = { "\x04", "\x08", "\x0a", "\x10", "\x7f", "\e[A",
	"\e[B", "\e[C", "\e[D", "\e[F", "\e[H", "\e[3~", "\e[1;5A", "\e[1;5B",
	"\e[1;5C", "\e[1;5D", NULL };

	if (sh->state != HGL && ft_isprint(*sh->inp.rbuf))
	{
		evt_printable(sh);
		return ;
	}
	i = -1;
	while (fptrs[++i])
		if (ft_strequ(sh->inp.rbuf, keys[i]))
			fptrs[i](sh);
}
