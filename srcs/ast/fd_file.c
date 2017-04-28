/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 14:36:25 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/28 12:52:07 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast/ast.h"

int			open_right(t_lexem *lexem)
{
	return (open(lexem->name_lexem, O_RDWR | O_CREAT | O_TRUNC, 0644));
}

void			gestion_fd(t_node *ast)
{
	int			count;

	count = 0;
	while (ast && ast->body->lexem->token_type == OP_SP_LOG)
		ast = ast->left_op;
	if (ast != NULL)
	{
		if (ast && ast->body->lexem->token_type == OP_FILES &&
			!ft_strncmp(ast->parent->body->lexem->name_lexem, ">>", 2))
			ast->body->fd = open(ast->body->lexem->name_lexem,
									O_RDWR | O_CREAT | O_APPEND, 0644);
		else if (ast && ast->body->lexem->token_type == OP_FILES &&
			!ft_strncmp(ast->parent->body->lexem->name_lexem, ">", 1))
			ast->body->fd = open_right(ast->body->lexem);
		else if (ast && ast->body->lexem->token_type == OP_FILES &&
			!ft_strncmp(ast->parent->body->lexem->name_lexem, "2>", 1))
			ast->body->fd = open_right(ast->body->lexem);
		else if (ast && ast->body->lexem->token_type == OP_FILES &&
			!ft_strncmp(ast->parent->body->lexem->name_lexem, "<", 1))
			ast->body->fd = open(ast->body->lexem->name_lexem,
							O_RDWR , 0644);
		gestion_fd(ast->left_op);
		gestion_fd(ast->right_op);
	}
}
