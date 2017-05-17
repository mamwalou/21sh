/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:29:43 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 02:19:36 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

void				stock_line(t_lexem *begin, int code_mode)
{
	int				pos;

	pos = 0;
	if (code_mode == HEREDOC_CODE)
	{
		while (g_memory.line[pos] &&
			!ft_findstr(g_memory.line + pos, g_memory.key_ctrl))
			pos++;
		g_memory.line_mode = ft_strndup(g_memory.line, 0, pos);
	}
	else
		g_memory.line_mode = ft_strdup(g_memory.line);
}
