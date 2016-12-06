/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:21:25 by salomon           #+#    #+#             */
/*   Updated: 2016/12/05 16:38:17 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"
#include "../../includes/ast/ast.h"

void 			save_node(t_node **node, char *line, int begin, int end)
{
	t_node		*new_node;

	new_node = (t_node*)ft_memalloc(sizeof(t_node));

	*node = new_node;
}

int				find_token(t_node **node, char *line)
{
	char		*tableau;
	int			count;
	int			lenght;
	int			tmp;

	count = 0;
	tmp = 0;
	tableau = ft_strdup(" ");
	lenght = ft_strlen(line);
	while (count < lenght)
	{
		ft_putchar(line[count]);
		if ((tmp = operator_filters(line)) > 0)
		{
			count += tmp;
			//save_node(node, save + count, pos, count);
		}
		if ((tmp = ft_strint(line + count, tableau)) > 0)
			count += tmp;

	}
	exit(1);
	free(tableau);
	return (0);
}

t_node			*build_node(char *line)
{
	t_node		*node_bck;

	node_bck = NULL;
	find_token(&node_bck, line);
	return (node_bck);
}

void 		parser(char *line)
{
	t_node	*node;

	node = NULL;
	node = build_node(line);
}
