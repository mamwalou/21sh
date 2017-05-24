/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_restore_default.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 01:55:32 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/11 02:05:10 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	tc_restore_default(t_memory *sh)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &(sh->term_d)) < 0)
		sh_abort("cannot set terminal attributes");
}
