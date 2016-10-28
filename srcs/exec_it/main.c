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
	t_win			win;
	int				ctrl;

	ctrl = 0;
	win.set = 0;
	memory.var = NULL;
	env = (t_llist*)ft_memalloc(sizeof(t_llist));
	env = build_env(environ);
	while (ctrl >= 0)
	{
		if (env == NULL)
			env = my_setenv();
		memory.line = NULL;
		if ((termcaps(env, &memory, prompt(env), &win)) == -1)
			return (-1);
		ft_putchar('\n');
		if (memory.line)
			ctrl = exec_cmd(&memory, &env);
		if (ctrl == 1)
			env = NULL;
		free(memory.line);
	}
	return (0);
}
