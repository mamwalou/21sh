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


static void		save_node(t_node **node, char *line, int end, int begin)
{
	t_node		*new_node;
	t_node		*ptr;

	new_node = (t_node*)ft_memalloc(sizeof(t_node));
	new_node->name_node = ft_strndup(line, 0, end - begin);
	new_node->next = NULL;
	new_node->token_type = define_token(new_node->name_node)
	ft_putendl(new_node->name_node);

	if (*node == NULL)
	{
		*node = new_node;
		return ;
	}
	else
	{
		ptr = *node;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new_node;
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
	exit(1);
	free(tableau);
	return (0);
}


void 		parser(char *line)
{
	t_node	*node;

	node = NULL;
	find_token(&node, line);
}
