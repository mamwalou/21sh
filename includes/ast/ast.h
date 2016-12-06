/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
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
	t_token				token_type;
	char				**option;
	char				*name_node;
	int					index;
	struct s_node		*next;
}						t_node;

typedef struct 			s_tree
{

	struct s_tree		*root;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

t_token					define_token(char *lexem);

#endif
