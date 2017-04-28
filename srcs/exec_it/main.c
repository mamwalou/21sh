/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/25 16:55:10 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include "../../includes/termcaps/termcaps.h"

int					prompt(void)
{
	char			*user;
	char			*pwd;
	int				lenght_prompt;

	lenght_prompt = 0;
	if ((user = ft_strjoin("\033[1;31m", search_env(g_env, "USER="))) != NULL)
	{
		lenght_prompt = ft_strlen(search_env(g_env, "USER="));
		ft_putstr(user);
		ft_putstr("\033[0m:");
		free(user);
	}
	if ((pwd = ft_strjoin("\033[1;69m", search_env(g_env, "PWD="))) != NULL)
	{
		lenght_prompt += ft_strlen(search_env(g_env, "PWD="));
		ft_putstr(pwd);
		ft_putstr("\033[0m:");
		free(pwd);
	}
	ft_putstr(" $>");
	return (lenght_prompt + 3);
}

void 				end_memory(void)
{
	g_memory.code_history = 0;
	g_memory.line = NULL;
	g_memory.launch = 0;
	g_memory.mode = SHELL;
}

int					main(int argc, char **argv, char **environ)
{
	t_mode			mode;
	int				ctrl;

	ctrl = 0;
	mode = SHELL;
	g_env = build_env(environ);
	init_memory();
	while (42)
	{
		termcaps();
		if (g_memory.line)
		{
			g_memory.mode = lexer_parser(&g_memory);
			if (g_memory.mode == SHELL)
			{
				push_history();
				free(g_memory.line);
				g_memory.line = NULL;
			}
		}
	}
	end_memory();
	return (0);
}
