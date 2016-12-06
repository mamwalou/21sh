/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include "../libft/Includes/libft.h"
# include <unistd.h>
# include <signal.h>
# include <stdio.h>

# define NB_BUILT 8

# define SUCCESS 0
# define ER_CMDNF -1
# define ER_MMR 32
# define ER_PREMMR 33
# define ER_NOENVSET 99
# define ER_PATHNF 2
# define ER_CDPWDNF 43
# define ER_USEVR 45
# define ER_NTFORD 66
# define ER_EXIT 42
# define ER_NOVSET 47
# define ER_VARARLE 7
# define OPEN_QUOTE_MODE 2
# define QUOTE_OPT 66

typedef	struct		s_hst
{
	char			*line;
	struct s_hst	*next;
	struct s_hst	*prev;
}					t_hst;

typedef struct		s_memory
{
	char			*var;
	char			*line;
	char			*mode_quote;
	int				*type_quote;
	int				ll;
	pid_t			father;
	pid_t			child;
	struct s_hst	*head;
	struct s_hst	*tail;
}					t_memory;


/*error gestion*/

/*exec_cmd*/
int					prompt(t_llist *env);

/*data*/

/*env*/
t_llist				*build_env(char **environ);
int					count_env(t_llist *env);
char				*search_env(t_llist *env, const char *value);

/*parser and lexer*/
int					operator_filters(char *line);
int					ctrl_var(char *line);
int					my_ctrl(int test);
int					is_bulltin(char *cmd);
int					operator_ctrl(int test);
int					find_str(char *line);

/*builltin*/
t_llist				*my_setenv();
char				**my_env(t_llist *env);
int					unenv(char *unset, t_llist *env);
int					env_collapse(t_llist *env, const char *value);

/*memory gestion*/
t_memory 			init_memory();
void 				push_history(t_memory *memory);

/*free gestion*/
void				free_d(char **dtab, int lenght);

#endif
