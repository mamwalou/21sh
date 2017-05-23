/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/23 11:44:50 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

static void			option_lexem(t_st_lexem *lex, t_lexem *new)
{
	if ((new->option = init_option(new->name_lexem, new->option, new->index)))
	{
		lex->save = new;
		new->index++;
	}
}

void				push_lexem(t_st_lexem *lex, t_lexem *new)
{
	if ((lex->end_lexem->token_type == OP_REDIR_LEFT ||
		lex->end_lexem->token_type == OP_REDIR_RIGHT))
	{
		new->token_type = OP_FILES;
		new->priority = define_prio(new->token_type);
	}
	else if (find_varibale(new->name_lexem, '=') > 0 &&
				lex->end_lexem->token_type != CMD)
	{
		new->token_type = VARIABLE;
		new->priority = define_prio(new->token_type);
	}
	new->prev = lex->end_lexem;
	lex->end_lexem->next = new;
	lex->end_lexem = new;
	if (new->token_type == CMD)
	{
		option_lexem(lex, new);
		lex->nb_of_lexem++;
	}
}

static void			ctrl_lexem(t_st_lexem *lex, char *tmp, t_lexem *new)
{
	if (lex->end_lexem->token_type == OP_FILES && new->token_type == CMD)
	{
		lex->save->option = init_option(tmp, lex->save->option,
												lex->save->index);
		lex->save->index++;
		free_lexem(new);
		return ;
	}
	if (lex->end_lexem->token_type == CMD && new->token_type == CMD)
	{
		lex->end_lexem->option = init_option(tmp,
								lex->end_lexem->option, lex->end_lexem->index);
		lex->end_lexem->index++;
		free_lexem(new);
		return ;
	}
	push_lexem(lex, new);
}

void				save_lexem(t_st_lexem *lex, char *line, int end, int begin)
{
	t_lexem			*new;
	char			*tmp;
	char			*tmp2;

	tmp = ft_strndup(line, 0, end - begin);
	printf("(tmp =%s), (end=%d), (begin=%d))\n", tmp, end, begin);
	tmp2 = define_name_lexem(tmp);
	free(tmp);
	new = new_lexem(tmp2);
	if (lex->begin_lexem == NULL)
	{
		lex->begin_lexem = new;
		lex->end_lexem = new;
		lex->nb_of_lexem = 1;
		if ((find_varibale(new->name_lexem, '=')) > 0)
			new->token_type = VARIABLE;
		if (new->token_type == CMD)
			option_lexem(lex, new);
		free(tmp2);
		return ;
	}
	else
	{
		ctrl_lexem(lex, tmp2, new);
		free(tmp2);
	}
}
