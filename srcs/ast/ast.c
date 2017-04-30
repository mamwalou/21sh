/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 14:50:59 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast/ast.h"
#include "../../includes/prototypage/proto.h"

void			free_ast(t_node *ast)
{
	if (ast == NULL)
		return ;
	free_ast(ast->left_op);
	free_ast(ast->right_op);
	free_lexem(ast->body->lexem);
	free(ast->body);
	free(ast);
}

void			prev_g(t_lexem *max, t_node **ast, t_lexem *tmp, t_st_lexem *l)
{
	if (tmp->priority == 0)
		full_leaf(&(*ast)->left_op, ast, create_node(tmp, l));
	else
		add_node(&(*ast)->left_op, ast, create_node(tmp, l));
}

void			prev_d(t_lexem *max, t_node **ast, t_lexem *tmp, t_st_lexem *l)
{
	if (tmp->priority == 0)
		full_leaf(&(*ast), ast, create_node(tmp, l));
	else
		add_node(&(*ast)->right_op, ast, create_node(tmp, l));
}

static t_node	*create_node_frst(t_lexem *ptr, int index)
{
	t_node		*new_node;

	new_node = (t_node*)ft_memalloc(sizeof(t_node));
	new_node->body = (t_body_node*)ft_memalloc(sizeof(t_body_node));
	new_node->body->lexem = (t_lexem*)ft_memalloc(sizeof(t_lexem));
	new_node->left_op = NULL;
	new_node->right_op = NULL;
	new_node->body->type_node = BEGIN;
	new_node->body->lexem->token_type = ptr->token_type;
	new_node->body->lexem->index = 0;
	new_node->body->fd = 1;
	new_node->body->lexem->index = 0;
	new_node->body->lexem->option = NULL;
	while (index > 0)
	{
		new_node->body->lexem->option = init_option(
				ptr->option[new_node->body->lexem->index],
				new_node->body->lexem->option, new_node->body->lexem->index);
		new_node->body->lexem->index++;
		index--;
	}
	new_node->body->lexem->name_lexem = ft_strdup(ptr->name_lexem);
	new_node->body->lexem->priority = ptr->priority;
	return (new_node);
}

void			generate_ast(t_st_lexem *lex)
{
	t_node		*ast;
	t_lexem		*max;
	t_lexem		*tmp;
	int			status;

	status = 0;
	max = find_op(lex);
	ast = create_node_frst(max, max->index);
	while (max->prev)
		prev_g(max, &ast, find_prev_max(max->prev), lex);
	while (max->next)
		prev_d(max, &ast, find_next_max(max->next), lex);
	free_lexem(max);
	free(lex);
	//saw_ast(ast, 0);
	exec_tree(ast, &status);
	free_ast(ast);
}
