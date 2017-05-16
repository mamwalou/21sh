/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 01:55:17 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"
#include "../../includes/prototypage/proto.h"

static int			parser(t_st_lexem **lexem, t_memory *memory)
{
	int				count;
	int				pos;
	int				tmp;

	count = 0;
	while (count < memory->line_lenght)
	{
		tmp = 0;
		pos = count;
		if ((tmp = ctrl_mode(memory->line + count, memory)) > 0)
		{
			if (tmp > SWITCH_MODE)
				return (tmp);
			count += tmp + 1;
			save_lexem(*lexem, memory->line + pos + 1, count - 2, pos);
		}
		else if ((tmp = find_token(memory->line + pos, (*lexem)->end_lexem)) > 0)
		{
			count += tmp;
			save_lexem(*lexem, memory->line + pos, count, pos);
		}
		else if (memory->line[count] == ' ' || memory->line[count] == '\t')
			count++;
	}
	return (0);
}

t_mode				lexer_parser(t_memory *memory)
{
	t_st_lexem		*lexem;
	int				code_mode;

	code_mode = 0;
	lexem = (t_st_lexem*)ft_memalloc(sizeof(t_st_lexem));
	if ((code_mode = parser(&lexem, memory)) > SWITCH_MODE)
	{
		stock_line(lexem->begin_lexem ,memory, code_mode);
		free_lexem(lexem->begin_lexem);
		free(lexem);
		free(g_memory.line);
		g_memory.line_lenght = 0;
		g_memory.line = NULL;
		if (code_mode == HEREDOC_CODE)
			return (HEREDOC);
		else if (code_mode == QUOTE_CODE)
			return (QUOTE);
		else if (code_mode == D_QUOTE_CODE)
			return (D_QUOTE);
	}
	sw_list(lexem);
	if (lexem->begin_lexem)
	{
		generate_ast(lexem);
		free(lexem);
	}
	return (SHELL);
}
