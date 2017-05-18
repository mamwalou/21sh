/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_home.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 13:56:37 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/18 18:52:17 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

int						end(t_win *win)
{
	while (win->cursor_line < win->lenght_line + 1)
	{
		win->cursor_line++;
		move_cursr(win, M_RIGHT, 1);
	}
	return (1);
}

int						home(t_win *win)
{
	while (win->cursor_line > 1)
	{
		win->cursor_line--;
		move_cursr(win, M_LEFT, 1);
	}
	return (1);
}
