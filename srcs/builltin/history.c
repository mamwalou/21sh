/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 14:43:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 07:57:51 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void		aff_history(char **history, int lenght)
{
	int			i;

	i = 0;
	if (lenght > 10)
		i = lenght - 10;
	while (i < lenght)
	{
		ft_putendl(history[i]);
		i++;
	}
}

static void		erase_history(void)
{
	int			fd;

	fd = open(search_env(g_env, "HISTORY="), O_WRONLY | O_TRUNC, 0666);
	write(fd, NULL, 0);
	g_memory.code_history = 0;
	close(fd);
}

void			history(char **cmd)
{
	char		**history;

	if (!search_env(g_env, "HISTORY="))
		return ;
	if (cmd[1] && !ft_strcmp(cmd[1], "-n"))
		erase_history();
	else if (!ft_strcmp(cmd[0], "history"))
	{
		history = convert_history();
		aff_history(history, g_memory.code_history);
		free_d(history, g_memory.code_history);
		free(history);
	}
}
