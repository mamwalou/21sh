/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static const t_built	g_builtin[NB_BUILT] =
{
	{"cd", ft_cd},
	{"env", ft_env},
	{"setenv", ft_setenv},
	{"export", ft_setenv},
	{"toexport", ft_toexport},
	{"unset", ft_unsetenv},
	{"var", ft_variable},
	{"echo", ft_echo},
};

void					exect_it(t_data *data, t_llist *env, t_memory *memory)
{
	pid_t				father;

	memory->father = fork();
	if (memory->father > 0)
	{
		wait(&memory->father);
		return ;
	}
	if (memory->father == 0)
		execve(data->cmd, data->option, NULL);
}

int						exec_parser(t_data *data, t_llist *env, t_memory *mem)
{
	int		i;
	int		tmp;

	i = 0;
	if ((is_bulltin(data->cmd)) != NULL && ft_strcmp(data->cmd, "exit"))
	{
		while (i < NB_BUILT)
		{
			if (!ft_strcmp(g_builtin[i].str, data->cmd))
			{
				tmp = g_builtin[i].f(data, env, mem);
				return (tmp);
			}
			i++;
		}
	}
	else if (!ft_strcmp(data->cmd, "exit"))
		return (42);
	else
		exect_it(data, env, mem);
	return (0);
}

int						exec_cmd(t_memory *memo, t_llist **env)
{
	t_data				*data;
	char				**pline;
	int					error;
	static int			count = 0;

	error = 0;
	data = build_data();
	if ((memo->ll = ft_strsplit(&pline, memo->line, generate(9, 32, 3))) == -1)
		return (0);
	if (memo->ll > 0)
	{
		error = parser_data(*env, pline, &data, &memo);
		if (error < 0)
		{
			ft_putstr(memo->line);
			manage_error(error, data, env, memo);
		}
		else if (error < 5)
		{
			if ((error = exec_parser(data, *env, memo)) != 0)
				return (manage_error(error, data, env, memo));
		}
	}
	free_d(pline, memo->ll);
	return (0);
}
