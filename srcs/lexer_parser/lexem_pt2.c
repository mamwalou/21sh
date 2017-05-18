/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexem_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 20:26:51 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 15:03:18 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

static int			lenght_name_lexem(char *line)
{
	int				count;
	int				lenght;

	count = 0;
	while (line[count])
	{
		if (line[count] != '\\')
		{
			lenght++;
			count++;
		}
		else
			count++;
	}
	return (lenght);

}

char				*define_name_lexem(char *line)
{
	char			*str;
	int				lenght;
	int				i;
	int				j;

	i = 0;
	j = 0;
	lenght = lenght_name_lexem(line);
	str = (char*)ft_memalloc(sizeof(char) * lenght);
	while (line[j])
	{
		if (line[j] != '\\')
		{
			str[i++] = line[j];
		}
		j++;
	}
	str[i] = 0;
	return (str);
}

void				arg_spe_sep(t_st_lexem *lex, char *line)
{
	t_lexem			*arg_files;

	arg_files = (t_lexem*)ft_memalloc(sizeof(t_lexem));
	arg_files->name_lexem = define_name_lexem(line);
	arg_files->next = NULL;
	arg_files->prev = NULL;
	arg_files->index = 0;
	arg_files->option = NULL;
	arg_files->token_type = OP_SP_LOG;
	arg_files->priority = define_prio(arg_files->token_type);
	push_lexem(lex, arg_files);
}
