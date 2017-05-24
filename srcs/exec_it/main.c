/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 12:54:23 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "termcaps.h"

int	dfd = -1;

int					find_varibale(char *str, char c)
{
	int				count;

	count = 0;
	while (str[count])
	{
		if (str[count] == c)
			return (1);
		count++;
	}
	return (-1);
}

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
	if (g_memory.variable != NULL)
		ft_lstdel(&(g_memory.variable), ft_bzero);
	if (g_memory.line_mode != NULL)
		free(g_memory.line_mode);
}

void	test(void)
{
	switch (g_memory.mode)
	{
		case SHELL :
			dprintf(dfd, "SHELL\n");
			break ;
		case HEREDOC :
			dprintf(dfd, "HEREDOC\n");
			break ;
		case QUOTE :
			dprintf(dfd, "QUOTE\n");
			break ;
		case D_QUOTE :
			dprintf(dfd, "DQUOTE\n");
			break ;
		case BACKQUOTE :
			dprintf(dfd, "BQUOTE\n");
			break ;
		case BCKSLASH :
			dprintf(dfd, "BSLASH\n");
			break ;
		case ERROR :
			dprintf(dfd, "ERROR\n");
			break ;
	}
}

void				init(void)
{
	if ((dfd = open("/dev/ttys002", O_WRONLY)) == -1)
		ft_putendl("log init failed");
	sig_init();
	g_env = build_env();
	ft_bzero(&g_memory, sizeof(t_memory));
	tc_init(&g_memory);
	g_memory.mode = SHELL;
	get_histfile_path();
	if (is_dir(search_env(g_env, "HISTORY=")) == FILES)
		hst_retrieve(&g_memory);
	ft_putstr_fd(PROMPT, STDERR_FILENO);
}

//handler(&g_memory);
			// else if (g_memory.mode == HEREDOC)
			// {
			// 	printf("line %s\n", g_memory.line_mode);
			// 	printf("key %s\n", g_memory.key_ctrl);
			// 	printf("line after %s\n", g_memory.line_mode_after);
			// }

int					main(void)
{
	t_mode			mode;

	init();
	mode = SHELL;
	while (42)
	{
		termcaps(&g_memory);
		if (g_memory.inp.cmdlen > 0)
		{
			g_memory.mode = lexer_parser(&g_memory);
			test();
			if (g_memory.mode == SHELL)
			{
				hst_push(&g_memory, NULL);
				g_memory.line = NULL;
				g_memory.line_lenght = 0;
			}
			else
				;
		}
		cbuf_reset(&g_memory);
	}
	end_memory();
	return (0);
}
