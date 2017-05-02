/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 13:17:31 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

void			bring_back_shell(struct termios *term)
{
	if (tcsetattr(0, 0, term) == -1)
		return ;
}

void			init_mv(t_win *win)
{
	win->lenght_line = 0;
	win->cursor_line = 1;
	win->pos_history = g_memory.code_history - 1;
	win->y = 0;
	win->x = 0;
	win->begin = NULL;
	win->end = NULL;
	win->hst = NULL;
	win->hst = convert_history(g_memory.history_path, g_memory.code_history);
	ioctl(0, TIOCGWINSZ, &(g_term.apt));
}

int				init_term(struct termios *term)
{
	struct termios	new_term;
	char			*name_term;

	tcgetattr(0, term);
	if ((name_term = search_env(g_env, "TERM=")) == NULL)
	{
		ft_putendl_fd("big failur", 2);
		exit(1);
	}
	if (tgetent(NULL, name_term) == ERR)
		return (-1);
	if (tcgetattr(0, &new_term) == -1)
		return (-1);
	new_term.c_cc[VMIN] = 1;
	new_term.c_lflag &= ~(ICANON | ECHO);
	new_term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &new_term) == -1)
		return (-1);
	return (0);
}

void			termcaps(void)
{
	t_line		begin;
	t_line		end;
	t_win		win;

	if (init_term(&(g_term.terminal)) == -1)
		return ;
	if (g_memory.launch++ == 0)
		print_ascii();
	init_mv(&win);
	if (g_memory.mode == SHELL)
		g_memory.mode = shell_mode(&win);
	else if (g_memory.mode == HEREDOC)
		g_memory.mode = hered_mode(&win);
	else if (g_memory.mode == QUOTE)
		g_memory.mode = quote_mode(&win);
	else if (g_memory.mode == D_QUOTE)
		g_memory.mode = d_quote_mode(&win);
	if (win.hst != NULL)
	{
		free_d(win.hst, g_memory.code_history);
		free(win.hst);
	}
	return ;
}
