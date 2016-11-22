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
	if (tcgetattr(0, term) == -1)
		return ;
	term->c_lflag = (ICANON | ECHO | ISIG);
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

void		init_term(struct termios *term, t_llist *e, t_win *data, int len)
{
	char				*name_term;

	if ((name_term = search_env(e, "TERM=")) == NULL)
		name_term = ft_strdup("xterm-256color");
	if (tgetent(NULL, name_term) == ERR)
		return ;
	if (tcgetattr(0, term) == -1)
		return ;
	ft_bzero(data->buffer, 4);
	term->c_lflag &= ~(ICANON | ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	data->lenght = tgetnum("li");
	data->column = tgetnum("co");
	data->lineshell = 0;
	data->pos[0] = len + 1;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return ;
	if ((init_varfcurs()) == -1)
		return ;
}

int			termcaps(t_llist *env, t_memory *memo, int len)
{
	struct termios		term;
	int					code;
	t_win				win;

	init_term(&term, env, &win, len);
	while (win.buffer[0] != RETURN)
	{
		ft_bzero(win.buffer, 4);
		read(0, win.buffer, 4);
		if (win.buffer[0] == CTRL_D)
			termcaps_exit("close", &term);
		if ((ft_isalnum(win.buffer[0])) == 1 || (my_ctrl(win.buffer[0])) == 1)
		{
			memo->line = push_line(win.buffer[0], memo->line, &win);
			ft_putchar(win.buffer[0]);
		}
	}
	bring_back_shell(&term);
	return (0);
}
