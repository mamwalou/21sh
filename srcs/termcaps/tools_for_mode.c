/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:25:09 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 03:41:12 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "shell.h"

void		free_lchar(t_win *win)
{
	t_line	*ptr;

	ptr = win->begin;
	while (ptr)
	{
		ptr = ptr->next;
		free(win->begin);
		win->begin = ptr;
	}
	win->begin = NULL;
	win->end = NULL;
}

void		list_lchar(char *str, t_win *win)
{
	int		i;
	int		y;

	y = 0;
	i = 0;
	while (str[y])
	{
		if (str[y] == ';' && i == 0)
			i = y + 1;
		y++;
	}
	while (str[i])
	{
		push_line(win, str[i]);
		i++;
	}
}

char		*lchar_list(t_line *line, int lenght)
{
	char	*str;
	t_line	*ptr;
	int		i;

	i = 0;
	ptr = line;
	str = (char*)ft_memalloc(sizeof(char) * lenght + 1);
	while (i < lenght)
	{
		str[i] = ptr->l_char;
		ptr = ptr->next;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void		printline(t_line *begin)
{
	t_line	*ptr;

	ptr = begin;
	while (ptr)
	{
		ft_putchar(ptr->l_char);
		ptr = ptr->next;
	}
}

int			stop_her(t_line **end)
{
	t_line	*ptr;
	t_line	*save;
	int		len;

	ptr = *end;
	len = ft_strlen(g_memory.key_ctrl) - 1;
	while (ptr && g_memory.key_ctrl[len] == ptr->l_char)
	{
		len--;
		ptr = ptr->prev;
	}
	if (len == -1)
	{
		g_memory.heredoc_sw = 1;
		return (0);
	}
	return (1);
}
