/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:30:28 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 18:43:20 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "termcaps.h"

void				treat_redirection(t_node *ast, int fd[3], int *status)
{
	pid_t			pid;

	pid = fork();
	if (pid == -1)
		ft_putendl_fd("fork don't work", 2);
	if (!pid)
	{
		dup2(fd[2], fd[0]);
		if (fd[1])
			dup2(fd[2], fd[1]);
		exec_tree(ast, status);
		exit(1);
	}
	close(fd[2]);
	wait(&pid);
}
