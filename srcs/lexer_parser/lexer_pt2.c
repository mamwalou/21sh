/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/16 19:21:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

int				ctrl_heredoc(t_memory *memory, char *line)
{
	char		*tmp;

	tmp = NULL;
	memory->key_ctrl = ft_strndup(line, 0, (find_str(line)));
	if (line + (find_str(line)))
		memory->line_mode_after = ft_strdup(line + find_str(line));
	return (HEREDOC_CODE);
}

int				ctrl_backslh(char *line)
{
	int			pos;
	int			y;

	pos = 0;
	y = 0;
	while (line[pos])
	{
		if (ft_isalnum(line[pos]) || line[pos] == ':')
		{
			y = 0;
			while (line[y] && !operator_filters(line + y) &&
					!redirection_filters(line + y))
				y++;;

		}
		pos++;
	}
	if (y)
		return (y);
	return (BCKSLASH_CODE);
}

int				ctrl_quot(int first, int second, char *line)
{

	if (first == 34)
		return (D_QUOTE_CODE);
	else if (first == 39)
		return (QUOTE_CODE);
	else if (first == 96)
		return (BACKQUOTE_CODE);
	else if (first == '\\')
		return (ctrl_backslh(line));
	else if (first == '<' && second == '<' && g_memory.heredoc_sw == 0)
		return (HEREDOC_CODE);
	return (0);
}

int				ctrl_mode(char *line, t_memory *memory)
{
	int			count;
	int			tmp;

	count = 0;
	if ((tmp = ctrl_quot(line[count], line[count + 1], line)) > 0)
	{
		count++;
		if (tmp == BCKSLASH_CODE)
			return (BCKSLASH_CODE);
		if (tmp == HEREDOC_CODE)
			return (ctrl_heredoc(memory, line + 3));
		if (tmp == D_QUOTE_CODE)
			memory->key_ctrl = ft_strdup("\"");
		if (tmp == QUOTE_CODE)
			memory->key_ctrl = ft_strdup("\'");
		if (tmp == BACKQUOTE)
			memory->key_ctrl = ft_strdup("`");
		while (line[count])
		{
			if (tmp == ctrl_quot(line[count], 0, line))
				return (count);
			count++;
		}
		return (tmp);
	}
	return (0);
}

int				is_bulltin(char *cmd)
{
	if (ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unsetenv") == 0
		|| ft_strcmp(cmd, "setenv") == 0
		|| ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "history") == 0
		|| ft_strcmp(cmd, "var") == 0)
		return (1);
	return (0);
}
