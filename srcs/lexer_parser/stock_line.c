/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 16:29:43 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/16 21:19:02 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

void				stock_line(t_lexem *begin, t_memory *memory, int code_mode)
{
	int				pos;

	pos = 0;
	while (memory->line[pos] &&
		!ft_findstr(memory->line + pos, g_memory.key_ctrl))
		pos++;
	g_memory.line_mode = ft_strndup(memory->line, 0, pos);
}
