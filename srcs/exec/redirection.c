/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 13:16:24 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 23:35:26 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void			ft_machon(char *token, int ret_fd[4], int pcr)
{
	char			*tmp;

	tmp = NULL;
	if (token[pcr] == '&' && token[pcr + 1] == '-')
	{
		ret_fd[3] = open("/dev/null",O_WRONLY | O_APPEND | O_CREAT, 0666);
	}
	else if (token[pcr] == '&')
	{
		pcr++;
		tmp = ft_strdup(token + pcr);
		ret_fd[2] = ft_atoi(tmp);
		free(tmp);
	}
	else
		ret_fd[3] = -1;
}

static void 		files_open(char *token, char *after, int ret_fd[4], int pcr)
{
	const char		*tableau[4];
	int				count;

	count = 0;
	tableau[0] = "<<";
	tableau[1] = ">>";
	tableau[2] = ">";
	tableau[3] = "<";
	while(count < 5)
	{
		if (!(ft_strncmp(tableau[count], token + pcr, ft_strlen(tableau[count]))))
		{
			if (count == 0)
			{
				if (!after)
					ft_machon(token , ret_fd, pcr + 2);
				else
				{
					ret_fd[0] = 0;
					ret_fd[2] = open(after, O_RDONLY | O_APPEND, 0666);
				}
			}
			if (count == 1)
			{
				if (!after)
					ft_machon(token , ret_fd, pcr + 2);
				else
				{
					ret_fd[0] = 1;
					ret_fd[2] = open(after, O_WRONLY | O_APPEND | O_CREAT, 0666);
				}
			}
			if (count == 2)
			{
				if (!after)
				{
					ft_machon(token, ret_fd, pcr + 1);
				}
				else
				{
					ret_fd[0] = 1;
					ret_fd[2] = open(after, O_WRONLY | O_TRUNC | O_CREAT, 0666);
				}
			}
			if (count == 3)
			{
				if (!after)
					ft_machon(token, ret_fd, pcr + 1);
				else
				{
					ret_fd[0] = 0;
					ret_fd[2] = open(after, O_RDONLY | O_TRUNC, 0666);
				}
			}
		}
		count++;
	}
}

static int			rediction_fd(int ret_fd[4], char *token)
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
	{
		ret_fd[1] = 2;
		pcr++;
	}
	return (pcr);
}

static int			*reacast_fd(char *token, char *after, int ret_fd[4])
{
	char			*tmp;
	int				pcr;

	pcr = 0;
	tmp = NULL;

	pcr = rediction_fd(ret_fd, token);
	files_open(token, after, ret_fd, pcr);
	return (ret_fd);
}

int					redirection_fonction(t_node *ast, int *status)
{
	int				fd[4];
	int				value;

	fd[0] = 0;
	fd[1] = 0;
	fd[2] = 0;
	fd[3] = 0;
	if (ast->right_op != NULL)
		reacast_fd(ast->body->lexem->name_lexem,
					ast->right_op->body->lexem->name_lexem, fd);
	else
		reacast_fd(ast->body->lexem->name_lexem, NULL, fd);
	if (ast->right_op &&
		(value = is_dir(ast->right_op->body->lexem->name_lexem)) != FILES)
	{
		if (value == REP)
			ft_putendl_fd("is a directory:", 2);
		else
			ft_putendl_fd("else", 2);
	}
	else if (fd[3] == -1)
		ft_putendl_fd("parse error near `'", 2);
	else
	{
		treat_redirection(ast->left_op, fd, status);
		ft_putnbr(fd[0]);
		ft_putnbr(fd[1]);
		ft_putnbr(fd[2]);
		ft_putnbr(fd[3]);
		ft_putchar('\n');
	}

	return (0);
}
