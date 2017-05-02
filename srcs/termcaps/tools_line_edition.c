/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_line_edition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 09:30:05 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 12:33:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

static char		*simpl_lchar(t_win *win)
{
	t_line		*ptr;
	char		*str;
	int			i;

	i = 0;
	str = (char*)ft_memalloc(sizeof(char) * win->lenght_line + 1);
	g_memory.line_lenght = win->lenght_line;
	ptr = win->begin;
	while (ptr)
	{
		str[i] = ptr->l_char;
		ptr = ptr->next;
		free(win->begin);
		win->begin = ptr;
		i++;
	}
	str[i] = '\0';
	return (str);
}

void			list_to_array(t_win *win)
{
	char		*save;

	save = NULL;
	if (win->begin != NULL)
	{
		if (g_memory.line != NULL)
		{
			save = ft_strdup(g_memory.line);
			free(g_memory.line);
		}
		g_memory.line = simpl_lchar(win);
	}
	if (save)
		g_memory.line = ft_strjoin(save, g_memory.line);
}

void			list_lchar(char *str, t_win *win)
{
	while (*str != ';')
		str++;
	str++;
	while (*str)
	{
		push_line(win, *str);
		str++;
	}
}

char			*lchar_list(t_line *line, int lenght)
{
	char	*str;
	t_line	*ptr;
	int		i;

	i = 0;
	ptr = line;
	str = (char*)ft_memalloc(sizeof(char) * lenght + 1);
	while (ptr)
	{
		str[i] = ptr->l_char;
		ptr = ptr->next;
		i++;
	}
	str[lenght + 1] = 0;
	return (str);
}
