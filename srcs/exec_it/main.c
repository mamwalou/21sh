/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 03:47:59 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include "../../includes/termcaps/termcaps.h"

void				print_ascii(void)
{
	ft_putstr("\033[1;36m");
	ft_putendl(" _____  ______   _______ _______ _______ _____   _____   ");
	ft_putendl("|  |  ||__    | |     __|   |   |    ___|     |_|     |_ ");
	ft_putendl("|__    |    __| |__     |       |    ___|       |       |");
	ft_putendl("   |__||______| |_______|___|___|_______|_______|_______|");
	ft_putstr("\033[0m");
}

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

void				end_memory(void)
{
	if (g_memory.line)
		free(g_memory.line);
	if (g_memory.key_ctrl)
		free(g_memory.key_ctrl);
	if (g_memory.variable == NULL)
		ft_lstdel(&(g_memory.variable), ft_bzero);
	if (g_memory.line_mode == NULL)
		free(g_memory.line_mode);
	if (g_memory.line_mode_tmp)
		free(g_memory.line_mode_tmp);
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
