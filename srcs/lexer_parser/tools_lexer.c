/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:05:10 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/16 23:05:27 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

int				ctrl_tab(char *line, const char **tableau, int itr)
{
	int			count;
	int			i;

	i = 0;
	count = 0;
	while (i < itr)
	{
		if (!ft_strncmp(tableau[i], line, ft_strlen(tableau[i])))
		{
			count += ft_strlen(tableau[i]);
			if (!(ft_strcmp(tableau[i], "<<")))
				g_memory.heredoc_sw = 0;
			if (line[count] == '&')
			{
				count++;
				while (ft_isdigit(line[count]))
					count++;
			}
			return (count);
		}
		i++;
	}
	return (0);
}
