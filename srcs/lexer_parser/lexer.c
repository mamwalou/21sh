/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/12/05 16:30:04 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			ctrl_var(char *line)
{
	int		i;

	i = 0;
	while (ft_isalpha(line[i]))
		i++;
	if (line[i] == '=' && i > 0)
		return (0);
	return (1);
}

int				operator_filters(char *line)
{
	const char	*tableau[7];
	int			i;

	tableau[0] = ">";
	tableau[1] = "<";
	tableau[2] = ">&";
	tableau[3] = ">!";
	tableau[4] = ">!&";
	tableau[5] = "|";
	tableau[6] = ">>";
	tableau[7] = ">>&";
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
