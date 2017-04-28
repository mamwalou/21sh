/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_for_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:25:09 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/23 20:25:50 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

void		printline(t_line *begin)
{
	t_line *ptr;

	ptr = begin;
	while (ptr)
	{
		ft_putchar(ptr->l_char);
		ptr = ptr->next;
	}
}

int			stop_her(t_line *end)
{
	int len;

	len = g_memory.line_lenght - 1;
	while (end && g_memory.key_ctrl[len] == end->l_char)
	{
		len--;
		end = end->prev;
	}
	if (len == -1)
		return (0);
	return (1);
}
