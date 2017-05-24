/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:26:51 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 21:33:14 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

void				arg_spe_sep(t_st_lexem *lex, char *line)
{
	t_lexem			*arg_files;

	arg_files = (t_lexem*)ft_memalloc(sizeof(t_lexem));
	arg_files->name_lexem = ft_strdup(line);
	arg_files->next = NULL;
	arg_files->prev = NULL;
	arg_files->index = 0;
	arg_files->option = NULL;
	arg_files->token_type = OP_SP_LOG;
	arg_files->priority = define_prio(arg_files->token_type);
	push_lexem(lex, arg_files);
}
