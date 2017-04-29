/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:16:24 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 15:49:56 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

static void			redirection_leftsimple(t_node *ast, int *status)
{
	pid_t			pid;

	pid = fork();
	ast->right_op->body->fd = open(ast->right_op->body->lexem->name_lexem,
							O_RDONLY | O_CREAT | O_APPEND, 0644);
	if (pid == -1)
		ft_putendl_fd("fork don't work", 2);
	if (!pid)
	{
		dup2(ast->right_op->body->fd, STDIN_FILENO);
		exec_tree(ast->left_op, status);
		exit(1);
	}
	close(ast->right_op->body->fd);
	wait(0);
}

static void			redirection_rightsimple(t_node *ast, int *status)
{
	pid_t			pid;
	int				fd;

	pid = fork();
	if (!ft_strncmp(ast->body->lexem->name_lexem, ">>", 2))
		ast->right_op->body->fd = open(ast->right_op->body->lexem->name_lexem,
								O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		ast->right_op->body->fd = open(ast->right_op->body->lexem->name_lexem,
								O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pid == -1)
		ft_putendl_fd("fork don't work", 2);
	if (!pid)
	{
		dup2(ast->right_op->body->fd, STDOUT_FILENO);
		exec_tree(ast->left_op, status);
		exit(1);
	}
	close(ast->right_op->body->fd);
	wait(0);
}

static void			redirection_complex(t_node *ast, int *status)
{
	pid_t			pid;

	if (ast->body->lexem->name_lexem[0] == 2)
	{
		pid = fork();
		if (pid == -1)
			ft_putendl_fd("fork don't work", 2);
		if (!pid)
		{
			dup2(ast->right_op->body->fd, STDERR_FILENO);
			exec_tree(ast->left_op, status);
			exit(1);
		}
		close(ast->right_op->body->fd);
		wait(0);

	}
}

int					redirection_fonction(t_node *ast, int *status)
{
	if (!ft_strncmp(ast->body->lexem->name_lexem, ">>", 2) ||
		!ft_strncmp(ast->body->lexem->name_lexem, ">", 1))
		redirection_rightsimple(ast, status);
	else if (!ft_strncmp(ast->body->lexem->name_lexem, "<", 1))
		redirection_leftsimple(ast, status);
	else
		redirection_complex(ast, status);
	return (0);
}
