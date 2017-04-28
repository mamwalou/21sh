/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/28 05:25:06 by sbeline          ###   ########.fr       */
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
	win->lenght_line = 0; //start at 1  0 = no line
	win->cursor_line = 1; //cursor follow
	win->y = 0;
	win->begin = NULL;
	win->end = NULL;
	ioctl(0, TIOCGWINSZ, &(g_term.apt));
}

int					init_term(struct termios *term)
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

void			print_ascii(void)
{
	ft_putstr("\033[1;36m");
	ft_putendl(" _____  ______   _______ _______ _______ _____   _____   ");
	ft_putendl("|  |  ||__    | |     __|   |   |    ___|     |_|     |_ ");
	ft_putendl("|__    |    __| |__     |       |    ___|       |       |");
	ft_putendl("   |__||______| |_______|___|___|_______|_______|_______|");
	ft_putstr("\033[0m");
}

void			termcaps(void)
{
	t_line		begin;
	t_line		end;
	t_win		win;

	if (init_term(&(g_term.terminal)) == -1)
		return ;
	init_mv(&win);
	if (g_memory.launch++ == 0)
		print_ascii();
	if (g_memory.mode == SHELL)
	{
		g_memory.mode = shell_mode(&win);
		return ;
	}
	else if (g_memory.mode == HEREDOC)
		g_memory.mode = hered_mode(&win);
	else if (g_memory.mode == QUOTE)
		g_memory.mode = quote_mode(&win);
	else if (g_memory.mode == D_QUOTE)
		g_memory.mode = d_quote_mode(&win);
	return ;
}
