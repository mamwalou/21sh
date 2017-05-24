/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:30:28 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 23:39:42 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "termcaps.h"

void 				close_fd_chain(int fd[4])
{
	if (fd[2])
		close(fd[2]);
	if (fd[3])
		close(fd[3]);

}

void				treat_redirection(t_node *ast, int fd[4], int *status)
{
	pid_t			pid;

	pid = fork();
	if (pid == -1)
		ft_putendl_fd("fork don't work", 2);
	if (!pid)
	{
		if (fd[2])
			dup2(fd[2], fd[0]);
		if (fd[1])
			dup2(fd[2], fd[1]);
		if (fd[3])
		{
			dup2(fd[3], 1);
			dup2(fd[3], 2);
		}
		exec_tree(ast, status);
		exit(1);
	}
	close_fd_chain(fd);
	wait(&pid);
}
