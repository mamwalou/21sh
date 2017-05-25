/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 01:30:28 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/25 02:01:01 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "termcaps.h"

int					redirection_fonction(t_node *ast, int *status)
{
	t_list_fd		list_fd;
	int				value;

	if (ast->right_op != NULL)
		reacast_fd(ast->body->lexem->name_lexem,
					ast->right_op->body->lexem->name_lexem, &list_fd);
	else
		reacast_fd(ast->body->lexem->name_lexem, NULL, &list_fd);
	if (ast->right_op &&
		(value = is_dir(ast->right_op->body->lexem->name_lexem)) != FILES)
	{
		if (value == REP)
			ft_putendl_fd("is a directory:", 2);
		else
			ft_putendl_fd("else", 2);
	}
	else if (list_fd.fd[3] == -1)
		ft_putendl_fd("parse error near `'", 2);
	else
		treat_redirection(ast->left_op, list_fd.fd, status);
	return (0);
}

void				close_fd_chain(int fd[4])
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
