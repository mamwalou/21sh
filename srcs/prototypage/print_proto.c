/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_proto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:38:41 by salomon           #+#    #+#             */
/*   Updated: 2017/04/29 14:51:02 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/prototypage/proto.h"

void 			saw_ast(t_node *node, int indice)
{
	if (node != NULL)
	{
		if (indice == 0)
			ft_putstr("begin;");
		if (indice == 1)
			ft_putstr("left;");
		if (indice == 2)
			ft_putstr("right;");
		ft_putstr(">>>>>>");
		ft_putstr(node->body->lexem->name_lexem);
		ft_putstr("<<<<<<");
		if (node->body->lexem->option)
		{
			int i = 0;
			ft_putstr("index=");
			ft_putnbr(node->body->lexem->index);
			ft_putstr(";");
			while (i < node->body->lexem->index)
			{
				ft_putstr(" - ");
				ft_putstr(node->body->lexem->option[i]);
				i++;
			}
		}
		else
		{
			ft_putstr(node->body->lexem->name_lexem);
			ft_putstr("-------fd>");
			ft_putnbr(node->body->fd);
			ft_putstr("<fd-------");
		}
		if (node->body->type_node == LEAF)
			ft_putendl(";LEAF;");
		if (node->body->type_node == OP)
			ft_putendl(";OP;");
		if (node->body->type_node == BEGIN)
			ft_putendl(";BEGIN;");
		saw_ast(node->left_op, 1);
		saw_ast(node->right_op, 2);

	}
}


void 			wr(t_lexem *ptr){
	ft_putchar('\"');
	ft_putstr(ptr->name_lexem);
	ft_putchar('\"');
	if (ptr->token_type == OP_SP_LOG)
		ft_putstr("=SP_LOG");
	if (ptr->token_type == OP_FILES)
		ft_putstr("=OP_FILES");
	else if (ptr->token_type == OP_PIPE)
		ft_putstr("=OP_PIPE");
	else if (ptr->token_type == CMD)
		ft_putstr("=CMD");
	else if (ptr->token_type == ARG_FILES)
		ft_putstr("=ARG_FILES");
	else if (ptr->token_type == OP_REDIR_LEFT)
		ft_putstr("=OP_REDIR_LEFT");
	else if (ptr->token_type == OP_REDIR_RIGHT)
		ft_putstr("=OP_REDIR_RIGHT");
	else if (ptr->token_type == OP_ASS)
		ft_putstr("=OP_ASS");
	ft_putstr(" and prio value=");
	ft_putnbr(ptr->priority);
	ft_putchar('\n');
}

void 			sw_list(t_st_lexem *l)
{
	t_lexem *ptr;
	int i;

	ptr = l->begin_lexem;
	while (ptr)
	{
		wr(ptr);
		i = 0;
		if (ptr->option)
		{
			ft_putstr("index=");
			ft_putnbr(ptr->index);
			ft_putendl(";");
			while (i < ptr->index)
			{
				ft_putstr("-");
				ft_putendl(ptr->option[i]);
				i++;
			}
		}
		ptr = ptr->next;
	}
}

void 			rev_sw_list(t_st_lexem *l)
{
	t_lexem *ptr;
	int i;

	ptr = l->end_lexem;
	while (ptr)
	{
		wr(ptr);
		i = 0;
		if (ptr->option)
		{
			while (i < ptr->index)
			{
				ft_putstr("-");
				i++;
			}
		}
		ptr = ptr->prev;
	}
}
