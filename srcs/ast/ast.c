/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/07 22:09:27 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast/ast.h"
#include "../../includes/prototypage/proto.h"

void		free_ast(t_node *ast)
{
	if (ast == NULL)
		return ;
	free_ast(ast->left_op);
	free_ast(ast->right_op);
	free_lexem(ast->body->lexem);
	free(ast->body);
	free(ast);
}

void 		create(t_node **parent, t_node **ast, t_lexem *pos, t_st_lexem *lex)
{
	t_lexem	*prev;
	t_lexem	*next;

	prev = NULL;
	next = NULL;
	if (pos->next)
		next = find_next_max(pos->next, lex);
	if (pos->prev)
		prev = find_prev_max(pos->prev, lex);
	if (next && next->priority > 0)
	{
		pos->next->prev = NULL;
		pos->next = NULL;
	}
	if (*ast == NULL)
	{
		*ast = create_node(pos, lex, parent);
		if (next != NULL)
			create(&(*ast), &(*ast)->right_op, next, lex);
		if (prev != NULL)
			create(&(*ast), &(*ast)->left_op, prev, lex);
	}
}

void			generate_ast(t_st_lexem *lex)
{
	t_node	*ast;
	t_lexem	*begin;
	int		status;
	int		max;

	ast = NULL;
	status = 0;
	begin = find_op(lex);
	create(NULL, &ast, begin, lex);
	exec_tree(ast, &status);
	free_ast(ast);
}
