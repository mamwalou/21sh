/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_lexem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:36:06 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/22 00:15:09 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

int 				recall_q(char *line)
{
	int				count;

	count = 0;
	while (line[count] != '\"')
	{
		ft_putchar(line[count]);
		count++;
	}
	return (count - 1);
}

int 				recall_ob(char *line)
{
	int				count;

	count = 0;

	if (line[count] == '\\')
	{
		count++;
		ft_putchar(line[count]);
	}
	else
		ft_putchar(line[count]);
	count++;
	return (count);
}

char				*define_name_lexem(char *line)
{
	int				count;
	int				mode;


	count = 0;
	while (line[count])
	{
		mode = (line[count] == '\'' || line[count] == '\"') ? 1 : 0;
		if (mode == 1)
		{
			count++;
			count += recall_q(line + count);
			count++;
			mode = 0;
		}
		else
			count += recall_ob(line + count);
	}
	return (NULL);
}

t_lexem				*new_lexem(char *line)
{
	t_lexem			*new_lexem;

	new_lexem = (t_lexem*)ft_memalloc(sizeof(t_lexem));
	new_lexem->name_lexem = ft_strdup(line);
	new_lexem->next = NULL;
	new_lexem->prev = NULL;
	new_lexem->index = 0;
	new_lexem->option = NULL;
	new_lexem->token_type = define_token(new_lexem->name_lexem);
	new_lexem->priority = define_prio(new_lexem->token_type);
	return (new_lexem);
}

void				free_lexem(t_lexem *lexem)
{
	free(lexem->name_lexem);
	free_d(lexem->option, lexem->index);
	free(lexem->option);
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
