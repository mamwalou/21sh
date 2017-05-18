/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:05:07 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/18 19:37:58 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

int					my_ctrl(int test)
{
	if (test == '-'
		|| test == ';'
		|| test == '<'
		|| test == '>'
		|| test == '&'
		|| test == '='
		|| test == '/'
		|| test == '.'
		|| test == '|'
		|| test == '"'
		|| test == '$'
		|| test == '~'
		|| test == '_'
		|| test == 92
		|| test == 96
		|| test == 39
		|| test == ' '
		|| test == '!')
		return (1);
	return (0);
}

static void			loop(t_win *win, char buff[MAX_LEN + 4], int i, uint64_t *y)
{
	unsigned char	*s;

	i = 0;
	*y = 0;
	if (buff[0] != 10 && buff[0] != 4)
	{
		while (buff[i])
		{
			push_line(win, (int)buff[i]);
			i++;
		}
	}
	else
	{
		i = 0;
		s = (unsigned char*)buff;
		while (i < 8)
		{
			*y += (s[i] << (8 * i));
			i++;
		}
		push_line(win, *y);
	}
}

void				cursor_replace(t_win *win)
{
	while (win->y-- > 0)
		move_cursr(win, M_UP, 1);
	if (win->new_x > (win->prompt + win->cursor_line))
		while (win->new_x--)
			move_cursr(win, M_LEFT, 1);
	else if (win->new_x < (win->prompt + win->cursor_line))
		while (win->new_x++ < (win->prompt + win->cursor_line))
			move_cursr(win, M_RIGHT, 1);
	win->new_x = 1;
}

void				read_instance(t_win *win)
{
	uint64_t		y;
	int				z;

	z = 0;
	y = 0;
	ft_bzero(win->buffer, MAX_LEN + 1);
	while (y != 10 || (y == 10 && z != 0))
	{
		handl_sig();
		ft_bzero(win->buffer, MAX_LEN + 1);
		read(0, win->buffer, MAX_LEN);
		if (input(win) > 0)
			;
		else if (win->buffer[0] != RETURN)
			loop(win, win->buffer, 0, &y);
		else
		{
			list_to_array(win);
			bring_back_shell(&(g_term.terminal));
			ft_putchar('\n');
			return ;
		}
		z = (win->lenght_line > 0) ? 1 : 0;
	}
}
