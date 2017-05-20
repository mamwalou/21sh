/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/18 20:51:05 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"


void 			wr(t_lexem *ptr){
	ft_putchar('\"');
	ft_putstr(ptr->name_lexem);
	ft_putchar('\"');
	if (ptr->token_type == OP_SP_LOG)
		ft_putstr("=SP_LOG");
	if (ptr->token_type == OP_FILES)
		ft_putstr("=OP_FILES");
	else if (ptr->token_type == OP_PIPE)
		ft_putstr("=OP_PIPE");
	else if (ptr->token_type == CMD)
		ft_putstr("=CMD");
	else if (ptr->token_type == ARG_FILES)
		ft_putstr("=ARG_FILES");
	else if (ptr->token_type == OP_REDIR_LEFT)
		ft_putstr("=OP_REDIR_LEFT");
	else if (ptr->token_type == OP_REDIR_RIGHT)
		ft_putstr("=OP_REDIR_RIGHT");
	else if (ptr->token_type == OP_ASS)
		ft_putstr("=OP_ASS");
	ft_putstr(" and prio value=");
	ft_putnbr(ptr->priority);
	ft_putchar('\n');
}

void 			sw_list(t_st_lexem *l)
{
	t_lexem *ptr;
	int i;

	ptr = l->begin_lexem;
	while (ptr)
	{
		wr(ptr);
		i = 0;
		if (ptr->option)
		{
			ft_putstr("index=");
			ft_putnbr(ptr->index);
			ft_putendl(";");
			while (i < ptr->index)
			{
				ft_putstr("-");
				ft_putendl(ptr->option[i]);
				i++;
			}
		}
		ptr = ptr->next;
	}
}

void 			rev_sw_list(t_st_lexem *l)
{
	t_lexem *ptr;
	int i;

	ptr = l->end_lexem;
	while (ptr)
	{
		wr(ptr);
		i = 0;
		if (ptr->option)
		{
			while (i < ptr->index)
			{
				ft_putstr("-");
				i++;
			}
		}
		ptr = ptr->prev;
	}
}



/*****************************************************/
static int			parser(t_st_lexem **lex, t_memory *memory)
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
			count += tmp;
			save_lexem(*lex, memory->line + pos, count, pos);
		}
		else if ((tmp = find_token(memory->line + pos, (*lex)->end_lexem)) > 0)
		{
			if (tmp > SWITCH_MODE)
				return (tmp);
			count += tmp;
			save_lexem(*lex, memory->line + pos, count, pos);
		}
		else if (memory->line[count] == ' ' || memory->line[count] == '\t')
			count++;
	}
	return (0);
}

static t_mode		mode_gestion(t_st_lexem *lexem, int code)
{
	stock_line(lexem->begin_lexem, code);
	free_lexem(lexem->begin_lexem);
	free(lexem);
	free(g_memory.line);
	g_memory.line_lenght = 0;
	g_memory.line = NULL;
	if (code == HEREDOC_CODE)
		return (HEREDOC);
	else if (code == QUOTE_CODE)
		return (QUOTE);
	else if (code == D_QUOTE_CODE)
		return (D_QUOTE);
	else if (code == BCKSLASH_CODE)
		return (BCKSLASH);
	return (SHELL);
}

t_mode				lexer_parser(t_memory *memory)
{
	t_st_lexem		*lexem;
	int				code_mode;

	code_mode = 0;
	lexem = (t_st_lexem*)ft_memalloc(sizeof(t_st_lexem));
	if ((code_mode = parser(&lexem, memory)) > SWITCH_MODE)
		return (mode_gestion(lexem, code_mode));
	sw_list(lexem);
	if (lexem->begin_lexem)
	{
		generate_ast(lexem);
		free(lexem);
	}
	return (SHELL);
}
