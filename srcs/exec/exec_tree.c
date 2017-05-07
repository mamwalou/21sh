/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:32:22 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/07 22:09:28 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

static const t_exec			g_exec[NB_TOKEN] =
{
	{OP_SP_LOG, logique_fonction},
	{OP_REDIR_RIGHT, redirection_fonction},
	{OP_REDIR_LEFT, redirection_fonction},
	{OP_PIPE, pipe_function},
	{CMD, exec_fct},
};

void						exec_tree(t_node *ast, int *status)
{
	int						count;

	count = 0;
	while (g_exec[count].token != ast->body->lexem->token_type)
		count++;
	g_exec[count].f(ast, status);
}
