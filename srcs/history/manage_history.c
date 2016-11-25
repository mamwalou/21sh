/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_memory 			init_memory()
{
	t_memory		memory;
	char			*var;

	memory.var = NULL;
	memory.line = NULL;
	memory.mode_quote = 0;
	memory.type_quote = 0;
	memory.head = NULL;
	memory.tail = NULL;
	memory.father = 0;
	memory.ll = 0;
	return (memory);
}

static t_hst		*newhistory(char *line)
{
	t_hst			*maillon_hs;

	maillon_hs = (t_hst*)ft_memalloc(sizeof(t_hst));
	maillon_hs->line = ft_strdup(line);
	maillon_hs->next = NULL;
	maillon_hs->prev = NULL;
	return (maillon_hs);
}

void 				print_memory(t_hst *begin)
{
	t_hst			*ptr;

	ptr = begin;
	while (ptr)
	{
		ft_putendl(ptr->line);
		ptr = ptr->next;
	}
}

void 				push_history(t_memory *memory)
{
	t_hst			*new_maillon;

	if (memory->line != NULL)
	{
		new_maillon = newhistory(memory->line);
		if (memory->head == NULL)
		{
			memory->head = new_maillon;
			memory->tail = memory->head;
		}
		else
		{
			memory->tail->next = new_maillon;
			new_maillon->prev = memory->tail;
			memory->tail = new_maillon;
		}
		free(memory->line);
		memory->line = NULL;
	}
}
