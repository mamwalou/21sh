/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 22:43:43 by salomon           #+#    #+#             */
/*   Updated: 2017/04/28 14:01:34 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

# include "../../includes/shell.h"
# include "../../includes/prototypage/proto.h"
# include "../../includes/termcaps/termcaps.h"
# include "../../includes/lexer_parser/lexer_parser.h"
# include "../../includes/ast/ast.h"

void 			saw_ast(t_node *node, int indice);
void 			rev_sw_list(t_st_lexem *l);
void 			sw_list(t_st_lexem *l);
char			**get_in_env(t_llist *env, const char *str);

#endif
