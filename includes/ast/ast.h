/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:51:23 by salomon           #+#    #+#             */
/*   Updated: 2016/12/05 14:15:34 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

typedef enum			s_token
{
	R_RIGHT,
	R_LEFT,
	RR_RIGHT,
	RR_LEFT,
	SEQ,
	PIPE,
	AND,
	CMD,
}						t_token;

typedef struct			s_node
{
	t_token				*token_type;
	char				*name_node;
	struct s_node		*next;
}						t_node;

typedef struct 			s_tree
{

	struct s_tree		*root;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;


#endif
