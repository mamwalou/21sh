/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:16:24 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 03:26:11 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

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

static void 		files_open(char *token, char *after, int *ret_fd[3])
{
	const char		*tableau[4];
	int				count;
	int				i;

	i = 0;
	count = 0;
	while (ft_isdigit(token[count]))
		count++;
	count += (token[count] == '&') ? 1 : 0;
	tableau[0] = "<<";
	tableau[1] = ">>";
	tableau[2] = ">";
	tableau[3] = "<";
	while(i++ < 4)
	{
		if (!(ft_strncmp(token, tableau[i], ft_strlen(tableau[i]))))
		{
			if (tableau[i] == 0)
			
		}
		i++
	}
}

static void			rediction_fd(int *ret_fd[3], char *token)
{
	int				pcr;
	char			*tmp;

	pcr = 0;
	tmp = NULL;
	while (ft_isdigit(token[pcr]))
		pcr++;
	if (pcr > 0)
	{
		tmp = ft_strndup(token, 0, pcr);
		*ret_fd[0] = ft_atoi(tmp);
		free(tmp);
	}
	if (token[0] == '&')
		*ret_fd[1] = 1;
}

static int			*reacast_fd(char *token, char *after)
{
	char			*tmp;
	int				ret_fd[3];
	int				pcr;

	pcr = 0;
	ret_fd[0] = 0;
	ret_fd[1] = 0;
	ret_fd[2] = 0;
	tmp = NULL;
	rediction_fd(&ret_fd, token);
	if (after[0] == '&')
	{
		pcr = 0;
		while (ft_isdigit(token[pcr]))
			pcr++;
		if (pcr >= 1)
		{
			tmp = ft_strndup(after, 0, pcr);
			if ((ret_fd[2] = ft_atoi(tmp)) > 9)
				ret_fd[2] = -1;
			free(tmp);
		}
	}
	else
		files_open(token, after, &ret_fd);
	return (ret_fd);
}

int					redirection_fonction(t_node *ast, int *status)
{
	int				fd[3];

	fd[0] = 0;
	fd[1] = 0;
	fd[2] = 0;
	if (!ast->right_op)
	{
		ft_putendl_fd("parser prbl", 2);
		return (0);
	}
	fd = reacast_fd(ast->body->lexem->name_lexem,
					ast->right_op->body->lexem->name_lexem)
	return (0);
}
