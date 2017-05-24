/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 14:43:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 04:10:33 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

void	dbg_history(t_memory *sh)
{
	int	i;
	t_hlst	*lst;

	i = 0;
	lst = sh->hst.head;
	while (lst)
	{
		dprintf(dfd, "history[%u] = %s\n", i++, lst->cmd);
		lst = lst->next;
	}
}

static void		aff_history(t_hlst *lst)
{
	while (lst)
	{
		if (lst->line != NULL)
			ft_putendl(lst->line);
		lst = lst->next;
	}
}

static void		erase_history(void)
{
	int			fd;
	t_hlst		*tmp;

	fd = open(search_env(g_env, "HISTORY="), O_WRONLY | O_TRUNC, 0666);
	g_memory.code_history = 0;
	close(fd);
	if (g_memory.hst.head != NULL)
	{
		if (g_memory.hst.last_cmd != NULL)
			ft_strdel(&(g_memory.hst.last_cmd));
		while (g_memory.hst.head)
		{
			ft_strdel(&(g_memory.hst.head->line));
			tmp = g_memory.hst.head;
			g_memory.hst.head = g_memory.hst.head->next;
			free(tmp);
		}
		ft_bzero(&(g_memory.hst), sizeof(t_history));
	}
}

void			history(char **cmd)
{
	if (!search_env(g_env, "HISTORY="))
		return ;
	if (cmd[1] && !ft_strcmp(cmd[1], "-n"))
		erase_history();
	else if (!ft_strcmp(cmd[0], "history"))
		aff_history(g_memory.hst.head);
}
