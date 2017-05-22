/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode_termcaps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/16 21:21:18 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

t_mode			shell_mode(t_win *win)
{
	win->prompt = prompt();
	read_instance(win);
	return (SHELL);
}

t_mode			hered_mode(t_win *win)
{
	ft_putstr("heredoc>");
	ft_bzero(win->buffer, 4);
	while (42)
	{
		ft_bzero(win->buffer, 4);
		read(0, win->buffer, 4);
		if ((ft_isalnum(win->buffer[0])) == 1 || (my_ctrl(win->buffer[0])) == 1)
			push_line(win, win->buffer[0]);
		else
			input(win);
		if (*(unsigned int*)win->buffer == RETURN && stop_her(&(win)->end) == 0)
		{
			list_to_array(win);
			bring_back_shell(&(g_term.terminal));
			ft_putchar('\n');
			return (SHELL);
		}
		if (*(unsigned int*)win->buffer == RETURN)
			ft_putstr("\nheredoc>");
	}
	return (ERROR);
}

t_mode			quote_mode(t_win *win)
{
	ft_putstr("quote>");
	ft_bzero(win->buffer, 4);
	while (42)
	{
		ft_bzero(win->buffer, 4);
		read(0, win->buffer, 4);
		if ((ft_isalnum(win->buffer[0])) == 1 || (my_ctrl(win->buffer[0])) == 1)
			push_line(win, win->buffer[0]);
		else
			input(win);
		if (win->end->l_char == 39 && *(unsigned int*)win->buffer == RETURN)
		{
			list_to_array(win);
			bring_back_shell(&(g_term.terminal));
			ft_putchar('\n');
			return (SHELL);
		}
		if (*(unsigned int*)win->buffer == RETURN)
			ft_putstr("\nquote>");
	}
	return (ERROR);
}

t_mode			d_quote_mode(t_win *win)
{
	ft_putstr("dquote>");
	ft_bzero(win->buffer, 4);
	while (42)
	{
		ft_bzero(win->buffer, 4);
		read(0, win->buffer, 4);
		if ((ft_isalnum(win->buffer[0])) == 1 || (my_ctrl(win->buffer[0])) == 1)
			push_line(win, win->buffer[0]);
		else
			input(win);
		if (win->end->l_char == 34 && *(unsigned int*)win->buffer == RETURN)
		{
			list_to_array(win);
			bring_back_shell(&(g_term.terminal));
			ft_putchar('\n');
			return (SHELL);
		}
		if (*(unsigned int*)win->buffer == RETURN)
			ft_putstr("\ndquote>");
	}
	return (ERROR);
}

t_mode			backslash_mode(t_win *win)
{
	ft_putstr(">");
	ft_bzero(win->buffer, 4);
	while (42)
	{
		ft_bzero(win->buffer, 4);
		read(0, win->buffer, 4);
		if ((ft_isalnum(win->buffer[0])) == 1 || (my_ctrl(win->buffer[0])) == 1)
			push_line(win, win->buffer[0]);
		else
			input(win);
		if (*(unsigned int*)win->buffer == RETURN)
		{
			list_to_array(win);
			bring_back_shell(&(g_term.terminal));
			ft_putchar('\n');
			return (SHELL);
		}
		if (*(unsigned int*)win->buffer == RETURN)
			ft_putstr(">");
	}
	return (ERROR);
}
