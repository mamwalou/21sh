/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_sep.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 11:14:20 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 15:39:07 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			exec_fonc_and(t_node *ast, int *status)
{
	if (*status == 0)
		exec_tree(ast->left_op, status);
	if (*status == 0)
		exec_tree(ast->right_op, status);
}

void			exec_fonc_sep(t_node *ast, int *status)
{
	int			tmp;

	exec_tree(ast->left_op, &tmp);
	exec_tree(ast->right_op, status);
	if (tmp == 1 && *status == 1)
		*status = 1;
	else
		*status = 0;
}

void			exec_fonc_or(t_node *ast, int *status)
{
	if (*status == 0)
		exec_tree(ast->left_op, status);
	if (*status == 1)
		exec_tree(ast->right_op, status);
}

int				logique_fonction(t_node *ast, int *status)
{
	if (!(ft_strcmp(ast->body->lexem->name_lexem, "&&")))
		exec_fonc_and(ast, status);
	if (!(ft_strcmp(ast->body->lexem->name_lexem, ";")))
		exec_fonc_sep(ast, status);
	if (!(ft_strcmp(ast->body->lexem->name_lexem, "||")))
		exec_fonc_or(ast, status);
	return (0);
}
