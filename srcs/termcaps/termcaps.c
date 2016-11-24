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

void			bring_back_shell(struct termios *term)
{
	if (tcsetattr(0, 0, term) == -1)
		return ;
}

void 			list_to_array(t_memory *memory, t_line *begin, t_win *win)
{
	t_line		*ptr;
	int			i;

	i = 0;
	memory->line = (char*)ft_memalloc(sizeof(win->pos_line));
	ptr = begin;
	while (i < win->pos_line)
	{
		memory->line[i] = ptr->l_char;
		ptr = ptr->next;
		i++;
	}
	i = 0;
	while (i < win->pos_line)
	{
		begin->l_char = 0;
		free(begin);
		begin = begin->next;
		i++;
	}
}

void			init_mv(t_win *win, int lenght, t_line **begin, t_line **end)
{
	*begin = NULL;
	*end = NULL;
	win->pos_line = 0;
	win->x = lenght + 1;
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

int				termcaps(t_llist *env, t_memory *memo, int lenght_prompt)
{
	struct termios		term;
	t_line				*begin_l;
	t_line				*end_l;
	t_win				win;


	init_term(&(g_term.terminal), &(g_term.new_term));
	init_mv(&win, lenght_prompt, &begin_l, &end_l);
	while (*(unsigned int*)win.buffer != RETURN)
	{
		ft_bzero(win.buffer, 4);
		read(0, win.buffer, 4);
		if ((ft_isalnum(win.buffer[0])) == 1 || (my_ctrl(win.buffer[0])) == 1)
			push_line(&begin_l, &end_l, &win);
		else
			input(&begin_l, &end_l, memo, &win);
	}
	bring_back_shell(&(g_term.terminal));
	list_to_array(memo, begin_l, &win);
	return (0);
}
