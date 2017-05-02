/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_lexem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:36:06 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/23 14:08:34 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

void				free_lexem(t_lexem *lexem)
{
	free(lexem->name_lexem);
	free_d(lexem->option, lexem->index);
	lexem->priority = 0;
	free(lexem);
}

void				clear_lexem(t_lexem *lexem, t_st_lexem *lex)
{
	if (lexem->next == NULL && lexem->prev == NULL)
	{
		lex->begin_lexem = NULL;
		lex->end_lexem = NULL;
	}
	else if (lexem->prev == NULL)
	{
		lexem->next->prev = NULL;
		lex->begin_lexem = lexem->next;
	}
	else if (lexem->next == NULL)
	{
		lexem->prev->next = NULL;
		lex->end_lexem = lexem->prev;
	}
	else
	{
		lexem->prev->next = lexem->next;
		lexem->next->prev = lexem->prev;
	}
	free_lexem(lexem);
}
