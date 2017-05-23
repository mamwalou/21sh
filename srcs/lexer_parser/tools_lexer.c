/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:05:10 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/23 11:29:13 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

char			*epur_str(char *str, int c)
{
	char		*ret;
	int			count;
	int			lenght;

	lenght = 0;
	count = 0;
	while (str[count])
	{
		if (str[count] != c || str[count - 1] == c)
			lenght++;
		count++;
	}
	ret = (char*)ft_memalloc(lenght + 1);
	count = 0;
	lenght = 0;
	while (str[count])
	{
		if (str[count] != c || str[count - 1] == c)
			ret[lenght++] = str[count];
		count++;
	}
	ret[lenght + 1] = 0;
	return (ret);
}

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
			return (count);
		}
		i++;
	}
	return (0);
}
