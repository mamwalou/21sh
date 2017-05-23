/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_line_edition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 09:30:05 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/22 00:49:51 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "shell.h"

static char		*simpl_lchar(t_win *win, int minus)
{
	t_line		*ptr;
	char		*str;
	int			i;

	i = 0;
	str = (char*)ft_memalloc(sizeof(char) * win->lenght_line + 1);
	if (minus > win->lenght_line)
	{
		g_memory.line_lenght = 0;
		return (NULL);
	}
	else
		g_memory.line_lenght += win->lenght_line - minus;
	ptr = win->begin;
	while (ptr)
	{
		str[i] = ptr->l_char;
		ptr = ptr->next;
		free(win->begin);
		win->begin = ptr;
		i++;
	}
	win->begin = NULL;
	win->end = NULL;
	str[i] = 0;
	return (str);
}

int				purge_key(char *key, t_win **win)
{
	t_line		*ptr;
	t_line		*save;
	int			pos;

	ptr = (*win)->end;
	pos = ft_strlen(key) - 1;
	while (ptr && ptr->l_char == key[pos])
	{
		save = ptr;
		if (ptr->prev)
			ptr = ptr->prev;
		else
			ptr = NULL;
		free(save);
		pos--;
	}
	toto_function(ptr, win);
	pos = ft_strlen(key) - 1;
	free(g_memory.key_ctrl);
	g_memory.key_ctrl = NULL;
	return (pos);
}

static int		after_array(void)
{
	int			tmp;

	tmp = 0;
	if (g_memory.line)
		g_memory.line = ft_strjoin(g_memory.line, g_memory.line_mode_after);
	else
		g_memory.line = ft_strdup(g_memory.line_mode);
	tmp = ft_strlen(g_memory.line_mode_after);
	free(g_memory.line_mode_after);
	g_memory.line_mode_after = NULL;
	return (tmp);
}

static int		before_array(void)
{
	int			tmp;

	tmp = 0;
	g_memory.line = ft_strdup(g_memory.line_mode);
	tmp = ft_strlen(g_memory.line_mode);
	free(g_memory.line_mode);
	g_memory.line_mode = NULL;
	return (tmp);
}

void			list_to_array(t_win *win)
{
	int			tmp;
	int			minus;

	tmp = 0;
	minus = 0;
	if (g_memory.key_ctrl && g_memory.key_ctrl[0] != 39
		&& g_memory.key_ctrl[0] != 34 && g_memory.key_ctrl[0] != '\\')
		minus = purge_key(g_memory.key_ctrl, &win);
	if (g_memory.line_mode)
		tmp += before_array();
	if (win->begin != NULL)
	{
		/*if (g_memory.line)
			g_memory.line = ft_strjoin(g_memory.line, simpl_lchar(win, minus));
		else*/
		g_memory.line = simpl_lchar(win, minus);
	}
	/*if (g_memory.line_mode_after)
		tmp += after_array();
	if (tmp)
		g_memory.line_lenght += tmp;*/
}
