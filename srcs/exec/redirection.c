/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:16:24 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 19:49:46 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void 		files_open(char *token, char *after, int ret_fd[3])
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
	while(i < 4)
	{
		if (!(ft_strcmp(tableau[i], token + count)))
		{
			if (i == 0) // dont creat
			{
				ret_fd[0] = 0;
				ret_fd[2] = open(after, O_RDONLY | O_APPEND, 0666);
			}
			if (i == 1)
			{
				ret_fd[0] = 1;
				ret_fd[2] = open(after, O_WRONLY | O_APPEND | O_CREAT, 0666);
			}
			if (i == 2)
			{
				ret_fd[0] = 1;
				ret_fd[2] = open(after, O_WRONLY | O_TRUNC | O_CREAT, 0666);
			}
			if (i == 3)
			{ // dont creat
				ret_fd[0] = 0;
				ret_fd[2] = open(after, O_RDONLY | O_TRUNC, 0666);
			}
		}
		i++;
	}
}

static void			rediction_fd(int ret_fd[3], char *token)
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
		ret_fd[0] = ft_atoi(tmp);
		free(tmp);
	}
	if (token[0] == '&')
		ret_fd[1] = 2;
}

static int			*reacast_fd(char *token, char *after, int ret_fd[3])
{
	char			*tmp;
	int				pcr;

	pcr = 0;
	tmp = NULL;
	rediction_fd(ret_fd, token);
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
		files_open(token, after, ret_fd);
	return (ret_fd);
}

int					redirection_fonction(t_node *ast, int *status)
{
	int				fd[3];
	int				value;

	fd[0] = 0;
	fd[1] = 0;
	fd[2] = 0;
	if (!ast->right_op || !ast->right_op)
	{
		ft_putendl_fd("parser prbl", 2);
		return (0);
	}
	reacast_fd(ast->body->lexem->name_lexem,
					ast->right_op->body->lexem->name_lexem, fd);
	if ((value = is_dir(ast->right_op->body->lexem->name_lexem)) != FILES)
	{
		if (value == REP)
			ft_putendl_fd("is a directory:", 2);
		else
			ft_putendl_fd("else", 2);
	}
	ft_putnbr(fd[0]);
	ft_putnbr(fd[1]);
	ft_putnbr(fd[2]);
	treat_redirection(ast->left_op, fd, status);
	return (0);
}
