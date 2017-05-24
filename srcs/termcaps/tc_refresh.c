/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_refresh.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:52:15 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/24 17:53:21 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	tc_refresh(t_memory *sh)
{
	struct ttysize	ts;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
	sh->curs.x = sh->curs.i % ts.ts_cols;
	sh->curs.y = sh->curs.i / ts.ts_cols;
	sh->curs.x_max = ts.ts_cols - 1;
	sh->curs.y_max = sh->inp.cbuflen / ts.ts_cols;
	sh->curs.win_x = ts.ts_cols;
	if (sh->curs.y > 0)
		tc_write("UP+", 0, sh->curs.y);
	tc_write("ch+", 0, 0);
	tc_write("cd");
	sh->curs.s_i = sh->curs.i;
	sh->curs.i = 0;
	cbuf_print(sh, false);
	sh->curs.i = sh->curs.s_i;
	tc_write("ch+", 0, sh->curs.x);
}
