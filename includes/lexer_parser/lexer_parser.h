/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/23 11:10:16 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PARSER_H
# define LEXER_PARSER_H

# include "../../includes/shell.h"

typedef enum			e_token
{
	OP_SP_LOG,
	OP_ASS,
	OP_REDIR_RIGHT,
	OP_REDIR_LEFT,
	OP_PIPE,
	OP_FILES,
	VARIABLE,
	CMD,
	ARG_FILES,
}						t_token;

typedef struct			s_lexem
{
	t_token				token_type;
	char				**option;
	char				*name_lexem;
	int					index;
	int					priority;
	struct s_lexem		*next;
	struct s_lexem		*prev;
}						t_lexem;

typedef struct			s_st_lexem
{
	t_lexem				*pos;
	int					nb_of_lexem;
	int					fd_count;
	struct s_lexem		*save;
	struct s_lexem		*begin_lexem;
	struct s_lexem		*end_lexem;
}						t_st_lexem;

t_lexem					*new_lexem(char *line);
void					save_lexem(t_st_lexem *lex, char *line, int end,
									int begin);
void					clear_lexem(t_lexem *lexem, t_st_lexem *lex);
void					free_lexem(t_lexem *lexem);
t_lexem					*cpy_lexem(t_lexem *to_cpy);
void					push_lexem(t_st_lexem *lex, t_lexem *new);

int						define_prio(t_token token);
t_token					define_token(char *lexem);

void					redi_lexem(t_st_lexem *lex, char *tmp, t_lexem *new);
void					arg_spe_sep(t_st_lexem *lex, char *line);
void					arg_files(t_st_lexem *lex);

void					generate_ast(t_st_lexem *lex);

int						redirection_filters(char *line);
int						find_token(char *line);
int						ctrl_tab(char *line, const char **tableau, int itr);
void					stock_line(t_lexem *begin, int code_mode);
char					*define_name_lexem(char *line);
char					*epur_str(char *str, int c);

#endif
