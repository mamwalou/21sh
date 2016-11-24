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

t_llist				*created_path(int *tabulation, t_llist *e, char *value)
{
	DIR				*ptr;
	struct dirent	*fl;
	t_llist			*ret;
	int				lenght;

	ret = 0;
	if ((ptr = opendir(value)) == NULL)
		exit(1);
	while ((fl = readdir(ptr)) != NULL)
	{
		lenght = ft_strlen(fl->d_name);
		if (fl->d_name[0] != '.')
			ft_lstadd(&ret, ft_lstnew(fl->d_name, lenght));
		if (lenght > *tabulation)
			*tabulation = lenght;
	}
	return (ret);
}

void print_lsttmp(t_line *ptr)
{
	while (ptr)
	{
		ft_putchar(ptr->l_char);
		ptr = ptr->next;
	}
}

void				push_line(t_line **begin, t_line **end, t_win *win)
{
	t_line			*new;

	new = (t_line*)ft_memalloc(sizeof(t_line));
	new->l_char = win->buffer[0];
	new->next = NULL;
	new->prev = NULL;
	ft_putchar(new->l_char);
	win->pos_line++; 
	if (*begin == NULL)
	{
		*begin = new;
		*end = new;
	}
	else
	{
	 	(*end)->next = new;
		new->prev = *end;
		(*end) = new;
	}
}

int					depushline(t_line **begin, t_line **end, t_win *win)
{
	t_line			*to_free;

	if (win->pos_line > 0)
	{
		if (win->pos_line > 1)
		{
			to_free = *end;
			*end = (*end)->prev;
			(*end)->next = NULL;
			free(to_free);
			win->pos_line--;
		}
		else if (win->pos_line == 1)
		{
			free(*begin);
			*begin = NULL;
			*end = NULL;
			win->pos_line--;
		}
		move_cursr(win, 0, 1);
		ft_putchar(' ');
		move_cursr(win, 0, 1);
	}
	return (1);
}
