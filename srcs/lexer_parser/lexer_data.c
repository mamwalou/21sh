/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

int			operator_filters(char *line)
{
	char	*tableau[8];
	int		i;

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
		if (!ft_strcmp(tableau[i], line))
			return (1);
		i++;
	}
	return (-1);
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
		|| test == '"'
		|| test == '$'
		|| test == '~'
		|| test == '_'
		|| test == 92
		|| test == 39
		|| test == '!')
		return (1);
	return (0);
}

char		*is_bulltin(char *cmd)
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
		return (cmd);
	return (NULL);
}

char		*bin_checkout(char *line, t_llist *env)
{
	char	**b;
	char	*cpy;
	int		lenght_bin;
	int		i;

	i = 0;
	cpy = NULL;
	lenght_bin = ft_strsplit(&b, search_env(env, "PATH"), generate(58, 0, 2));
	while (i < lenght_bin)
	{
		if (((access(ft_strtrijoin(b[i], "/", line), X_OK)) == 0) ||
			((access(line, X_OK)) == 0))
		{
			if (ft_strrchr(line, '/'))
				cpy = ft_strdup(line);
			else
				cpy = (ft_strtrijoin(b[i], "/", line));
			free_d(b, lenght_bin);
			return (cpy);
		}
		i++;
	}
	free_d(b, lenght_bin);
	return (NULL);
}
