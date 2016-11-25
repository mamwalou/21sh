/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

void 		print_lsttmp(t_line *ptr)
{
	while (ptr)
	{
		ft_putchar(ptr->l_char);
		ptr = ptr->next;
	}
}

void		pos_in_line(t_line *new, t_line **begin, t_line **end, t_win *win)
{
	t_line	*ptr;
	t_line	*ptr_n;
	int		i;

	i = 0;
	ptr = *begin;
	while (++i < win->mov_line - 1)
		ptr = ptr->next;
	ptr_n = ptr->next;
	ptr->next = new;
	new->prev = ptr;
	new->next = ptr_n;
	win->pos_line++;
	print_lsttmp(ptr->next);
	move_cursr(win, 0, win->pos_line - win->mov_line);
	win->mov_line++;
}

void		push_line(t_line **begin, t_line **end, t_win *win)
{
	t_line	*new;

	new = (t_line*)ft_memalloc(sizeof(t_line));
	new->l_char = win->buffer[0];
	new->next = NULL;
	new->prev = NULL;
	if (*begin == NULL)
	{
		win->pos_line++;
		win->mov_line++;
		ft_putchar(new->l_char);
		*begin = new;
		*end = new;
	}
	else if ((win->mov_line - 1) == win->pos_line)
	{
		win->pos_line++;
		win->mov_line++;
		ft_putchar(new->l_char);
		ft_putchar(win->mov_line);
		(*end)->next = new;
		new->prev = *end;
		(*end) = new;
	}
	else
		pos_in_line(new, begin, end, win);
}

int			depushline(t_line **begin, t_line **end, t_win *win)
{
	t_line	*to_free;

	if (win->pos_line > 0)
	{
		if (win->pos_line > 1)
		{
			to_free = *end;
			*end = (*end)->prev;
			(*end)->next = NULL;
			free(to_free);
		}
		else if (win->pos_line == 1)
		{
			free(*begin);
			*begin = NULL;
			*end = NULL;
		}
		win->pos_line--;
		win->mov_line--;
		move_cursr(win, 0, 1);
		ft_putchar(' ');
		move_cursr(win, 0, 1);
	}
	return (1);
}
