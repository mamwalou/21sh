/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/28 14:08:27 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

int				operator_filters(char *line)
{
	const char	*tableau[5];
	int			i;

	i = 0;
	tableau[0] = "&&";
	tableau[1] = "||";
	tableau[2] = "&";
	tableau[3] = "|";
	tableau[4] = ";";
	while (i < 5)
	{
		if (!ft_strncmp(tableau[i], line, ft_strlen(tableau[i])))
			return (ft_strlen(tableau[i]));
		i++;
	}
	return (0);
}

int				redirection_filters(char *line)
{
	const char	*tableau[3];
	int			count;
	int			tmp;

	count = ft_isdigit(line[count])? 1 : 0;
	count = (line[count] == '&')? 1 :0;
	tableau[0] = ">>";
	tableau[1] = ">";
	tableau[2] = "<";
	if ((tmp = ctrl_tab(line + count, tableau, 3)) > 0)
		return (tmp + count);
	return (0);
}

int				find_str(char *line)
{
	int			count;

	count = 0;

	while ((line[count]) && (line[count] != ' ' && line[count] != '\t'))
		count++;
	if ((operator_filters(line + count)) > 0)
		return (count);
	if (ft_isdigit(line[count]) && !ft_isdigit(line[count - 1]))
		if ((redirection_filters(line + count)) > 0)
			return (count);

	return (count);
}

int				find_token(char *line)
{
	int			tmp;

	tmp = 0;
	if ((tmp = redirection_filters(line)) > 0)
		return (tmp);
	if ((tmp = operator_filters(line)) > 0)
		return (tmp);
	if ((tmp = find_str(line)) > 0)
		return (tmp);
	return (tmp);
}

int				is_bulltin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0
		|| ft_strcmp(cmd, "setenv") == 0
		|| ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "history") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "var") == 0)
		return (1);
	return (0);
}
