/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:05:10 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 17:16:09 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

void			epur_home(char **str, char **ptr)
{
	char		*ptr_after;
	char		*sigle;
	int			count;

	count = 0;
	sigle = NULL;
	ptr_after = *ptr;
	while ((ptr_after[count + 1]) != '\0' || (ptr_after[count] == ' '))
		count++;
	if ((sigle = search_env(g_env, "HOME=")))
	{
		free(*str);
		*str = ft_strdup(sigle);
	}
	else
		*str = NULL;
}

void			epur_variable(char **str, char **ptr)
{
	char		*ptr_after;
	char		*sigle;
	char		*putain;
	int			count;

	sigle = NULL;
	ptr_after = *ptr;
	count = 0;
	while ((ptr_after[count + 1]) != '\0' || (ptr_after[count] == ' '))
		count++;
	ptr_after += count;
	putain = ft_strjoin(*str + 1, "=");
	if ((sigle = search_env(g_env, putain)))
	{
		free(*str);
		*str = ft_strdup(sigle);
	}
	else
		*str = NULL;
	free(putain);
}

void 			epur_backslash(char **str, char *ptr_after)
{
	char		*tmp;

	tmp = NULL;
	tmp = ft_strdup(*str);
	free(*str);
	*str = ft_strjoin(tmp, ptr_after);
	free(tmp);
}

void			epur_str(char **str, int mode)
{
	char		*ptr;
	char		*ptr_after;

	ptr = NULL;
	if (((ptr = ft_strchr(*str, '\\')) != NULL) && (mode == 0))
	{
		*ptr = 0;
		ptr_after = ptr + 1;
		epur_backslash(str, ptr_after);
	}
	else if (((ptr = ft_strchr(*str, '$')) != NULL) && (mode == 0 || mode == 1))
		epur_variable(str, &ptr);
	else if (((ptr = ft_strchr(*str, '~')) != NULL) && (mode == 0 || mode == 1))
		epur_home(str, &ptr);
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
			if ((!(ft_strcmp(tableau[i], "<<"))) && g_memory.heredoc_sw == 1)
				g_memory.heredoc_sw = 0;
			else
				return (0);
			return (count);
		}
		i++;
	}
	return (0);
}
