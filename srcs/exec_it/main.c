/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include "../../includes/termcaps/termcaps.h"
#include <time.h>

int					prompt(t_llist *env)
{
	char			*user;
	char			*pwd;
	int				lenght_prompt;

	lenght_prompt = 0;
	if ((user = ft_strjoin("\033[1;31m", search_env(env, "USER="))) != NULL)
	{
		lenght_prompt = ft_strlen(search_env(env, "USER="));
		ft_putstr(user);
		ft_putstr("\033[0m:");
		free(user);
	}
	if ((pwd = ft_strjoin("\033[1;69m", search_env(env, "PWD="))) != NULL)
	{
		ft_putstr(pwd);
		ft_putstr("\033[0m:");
		lenght_prompt += ft_strlen(search_env(env, "PWD="));
		free(pwd);
	}
	ft_putstr(" $>");
	return (lenght_prompt + 3);
}

int					main(int argc, char **argv, char **environ)
{
	t_memory		memory;
	t_llist			*env;
	int				ctrl;

	ctrl = 0;
	memory.var = NULL;
	env = build_env(environ);
	while (ctrl >= 0)
	{
		memory.line = NULL;
		if ((termcaps(env, &memory, prompt(env))) == -1)
			return (-1);
		ft_putchar('\n');
		if (memory.line)
			ctrl = exec_cmd(&memory, &env);
		free(memory.line);
	}
	return (0);
}
