/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

void			move_cursr(t_win *win, int mode, int iteration)
{
	if (mode == 0)
		tputs(tgetstr("le", NULL), 1, ft_puts);
	if (mode == 1)
		tputs(tgetstr("ri", NULL), 1, ft_puts);
	if (mode == 2)
		tputs(tgetstr("up", NULL), 1, ft_puts);
}
