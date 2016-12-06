/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include "../../includes/ast/ast.h"

static	t_node	*new_node(char *line, int end, int begin)
{
	t_node		*new_node;

	new_node = (t_node*)ft_memalloc(sizeof(t_node));
	new_node->name_node = line;
	new_node->next = NULL;
	new_node->index = 0;
	new_node->option = (char**)ft_memalloc(sizeof(char*));
	new_node->token_type = define_token(new_node->name_node);
	return (new_node);
}

static void		save_node(t_node **node, char *line, int end, int begin)
{
	t_node		*ptr;
	char		*tmp;

	tmp = ft_strndup(line, 0, end - begin);
	if (*node == NULL)
	{
		*node = new_node(tmp, end, begin);
		return ;
	}
	else
	{
		ptr = *node;
		while (ptr->next != NULL)
			ptr = ptr->next;
		if (ptr->token_type == CMD)
			ptr->option = init_option(tmp, ptr->option, ptr->index);
		else
		{
			ptr->next = new_node(tmp, end, begin);
		}
	}
}

void 			sw_list(t_node *l)
{
	int i;
	while (l)
	{
		ft_putstr(l->name_node);
		i = 0;
		while (l->option[i])
			ft_putstr(l->option[i++]);
		l = l->next;
	}
}

int				find_token(t_node **node, char *line)
{
	char		*tableau;
	int			count;
	int			pos;
	int			lenght;
	int			tmp;

	count = 0;
	tmp = 0;
	tableau = ft_strdup(" ");
	lenght = ft_strlen(line);
	while (count < lenght)
	{
		pos = count;
		if ((tmp = operator_filters(line + count)) > 0)
		{
			count += tmp;
			save_node(node, line + pos, count, pos);
		}
		else if ((tmp = ft_strint(line + count, tableau)) > 0)
			count += tmp;
		if ((tmp = find_str(line + pos)) > 0)
		{
			count += tmp;
			save_node(node, line + pos, count, pos);
		}
	}
	sw_list(*node);
	free(tableau);
	exit(1);
	return (0);
}


void 		lexer_parser(char *line)
{
	t_node	*node;

	node = NULL;
	find_token(&node, line);
}
