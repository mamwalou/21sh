/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

void		bring_back_shell(struct termios *term)
{
	if (tcsetattr(0, 0, term) == -1)
		return ;
}

void		termcaps_exit(const char *exit_msg, struct termios *term)
{
	ft_putchar('\n');
	if (exit_msg)
		ft_putendl(exit_msg);
	bring_back_shell(term);
	exit(-1);
}

void				init_mv(t_win *win)
{
	win->x = 0;
	win->y = 0;
	ioctl(0, TIOCGWINSZ, &(g_term.apt));
	win->x_max = g_term.apt.ws_row;
	win->y_max = g_term.apt.ws_col;
}

int				init_term(struct termios *term, struct termios *new_term)
{
	char			*name_term;

	tcgetattr(0, term);
	if ((name_term = getenv("TERM")) == NULL)
		return (-1);
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, new_term) == -1)
		return (-1);
	new_term->c_cc[VMIN] = 1;
	new_term->c_lflag &= ~(ICANON | ECHO);
	new_term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, new_term) == -1)
		return (-1);
	return (0);
}
int			termcaps(t_llist *env, t_memory *memo, int len)
{
	struct termios		term;
	int					code;
	t_win				win;

	init_term(&(g_term.terminal), &(g_term.new_term));
	init_mv(&win);
	while (*(unsigned int*)win.buffer != RETURN)
	{
		ft_bzero(win.buffer, 4);
		read(0, win.buffer, 4);
		if (win.buffer[0] == CTRL_D)
			termcaps_exit("close", &term);
		if ((ft_isalnum(win.buffer[0])) == 1 || (my_ctrl(win.buffer[0])) == 1)
			push_line(win.buffer[0], memo, &win);
		else
			termc_ctrl(memo->line, &win, env, memo);
	}
	bring_back_shell(&(g_term.terminal));
	return (0);
}
