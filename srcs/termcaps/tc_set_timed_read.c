/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_set_timed_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 01:45:08 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/11 01:47:22 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	tc_set_timed_read(t_memory *sh)
{
	sh->term.c_cc[VMIN] = 0;
	sh->term.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &(sh->term)) < 0)
		sh_abort("cannot set terminal attributes");
}
