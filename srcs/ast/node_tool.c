/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 19:11:22 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 15:17:59 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_lexem			*rechatch_lexm(t_lexem *ptr)
{
	if (ptr->next != NULL)
	{
		if (ptr->prev)
			ptr->next->prev = ptr->prev;
		else
			ptr->next->prev = NULL;
	}
	if (ptr->prev != NULL)
	{
		if (ptr->next)
			ptr->prev->next = ptr->next;
		else
			ptr->prev->next = NULL;
	}
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

t_node			*create_node(t_lexem *ptr, t_node **parent)
{
	t_node		*new_node;

	new_node = (t_node*)ft_memalloc(sizeof(t_node));
	new_node->body = (t_body_node*)ft_memalloc(sizeof(t_body_node));
	new_node->left_op = NULL;
	new_node->right_op = NULL;
	if (parent != NULL)
		new_node->parent = *parent;
	new_node->body->lexem = rechatch_lexm(ptr);
	if (new_node->body->lexem->priority > 0)
		new_node->body->type_node = OP;
	else
		new_node->body->type_node = LEAF;
	new_node->body->fd = 1;
	return (new_node);
}
