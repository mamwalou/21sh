/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_and_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 22:27:14 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/25 17:37:00 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

void		list_to_array(t_win *win)
{
	t_line	*ptr;
	char	*save;
	int		i;

	i = 0;
	save = NULL;
	if (win->begin != NULL)
	{
		if (g_memory.line != NULL)
		{
			save = ft_strdup(g_memory.line);
			free(g_memory.line);
		}
		g_memory.line = (char*)ft_memalloc(sizeof(char) * win->lenght_line);
		g_memory.line_lenght = win->lenght_line;
		ptr = win->begin;
		while (ptr)
		{
			g_memory.line[i] = ptr->l_char;
			ptr = ptr->next;
			free(win->begin);
			win->begin = ptr;
			i++;
		}
		g_memory.line[i] = '\0';
	}
	if (save)
		g_memory.line = ft_strjoin(save, g_memory.line);
}
