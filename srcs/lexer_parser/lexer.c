/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			find_str(char *line)
{
	int		count;

	count = 0;
	while ((*line) && (ft_isalpha(*line) || ft_isdigit(*line)))
	{
		line++;
		count++;
	}
	return (count);
}


int				operator_filters(char *line)
{
	const char	*tableau[11];
	int			i;

	tableau[0] = ">!&";
	tableau[1] = ">>&";
	tableau[2] = ">&";
	tableau[3] = "&&";
	tableau[4] = "||";
	tableau[5] = ">!";
	tableau[6] = ">>";
	tableau[7] = ">";
	tableau[8] = "<";
	tableau[9] = ";";
	tableau[10] = "|";
	i = 0;
	while (i < 8)
	{
		if (!ft_strncmp(tableau[i], line, ft_strlen(tableau[i])))
			return (ft_strlen(tableau[i]));
		i++;
	}
	return (0);
}

int			my_ctrl(int test)
{
	if (test == '-'
		|| test == ';'
		|| test == '<'
		|| test == '>'
		|| test == '&'
		|| test == '='
		|| test == '/'
		|| test == '.'
		|| test == '|'
		|| test == '"'
		|| test == '$'
		|| test == '~'
		|| test == '_'
		|| test == 92
		|| test == 39
		|| test == ' '
		|| test == '!')
		return (1);
	return (0);
}

int			is_bulltin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0
		|| ft_strcmp(cmd, "setenv") == 0
		|| ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "toexport") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "var") == 0)
			return (1);
	return (0);
}
