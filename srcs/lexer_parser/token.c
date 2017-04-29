/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 15:39:08 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

int					define_prio(t_token token)
{
	if (token == CMD || token == ARG_FILES || token == OP_FILES)
		return (0);
	else if (token == OP_PIPE)
		return (1);
	else if (token == OP_REDIR_LEFT || token == OP_REDIR_RIGHT)
		return (2);
	else if (token == OP_SP_LOG)
		return (3);
	return (-1);
}

int					token_rr(char *line)
{
	const char	*tableau[2];
	int			count;
	int			tmp;
	int			i;

	i = 0;
	count = 0;
	count = ft_isdigit(line[count])? 1 : 0;
	if (line[count] == '&')
		count++;
	tableau[0] = ">>";
	tableau[1] = ">";
	if ((tmp = ctrl_tab(line + count, tableau, 2)) > 0)
		return (tmp + count);
	return (0);
}

int					token_left(char *line)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	count = ft_isdigit(line[count])? 1 : 0;
	if (line[count] == '&')
		count++;
	if (line[count] == '<')
	{
		count += 1;
		if (line[count] == '&')
		{
			count++;
			while (ft_isdigit(line[count]))
				count++;
		}
		return (count);
	}
	return (0);
}

t_token				define_token(char *lexem)
{
	int				i;

	i = 0;
	if (token_rr(lexem))
		return (OP_REDIR_RIGHT);
	if (token_left(lexem))
		return (OP_REDIR_LEFT);
	if (!ft_strncmp(lexem, "&&", 2))
		return (OP_SP_LOG);
	if (!ft_strncmp(lexem, "||", 2))
		return (OP_SP_LOG);
	if (!ft_strncmp(lexem, "&", 1))
		return (OP_ASS);
	if (!ft_strncmp(lexem, "|", 1))
		return (OP_PIPE);
	if (!ft_strncmp(lexem, ";", 1))
		return (OP_SP_LOG);
	return (CMD);
}
