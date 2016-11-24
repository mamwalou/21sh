/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

typedef struct		s_data
{
	int				index;
	int				*tableau;
	char			*cmd;
	char			**option;
	char			*operation;
	struct s_data	*left;
	struct s_data	*right;
}					t_data;

typedef	struct		s_hist
{
	char				*line;
	struct s_hist		hist;
}					t_hist;

typedef struct		s_memory
{
	char			*var;
	char			*line;
	char			*mode_quote;
	int				*type_quote;
	t_llist			*line_memory;
	pid_t			father;
}					t_memory;

typedef struct		s_built
{
	char			*str;
	int				(*f)(t_data *, t_llist *, t_memory *);
}					t_built;

/*error gestion*/
void				ft_print_error(char *error, const char *str);
int					manage_error(int cod, t_data *data, t_llist **env,
								t_memory *me);

/*exec_cmd*/
int					exec_cmd(t_memory *memo, t_llist **env);
int					prompt(t_llist *env);


/*parser and lexer*/
t_llist				*build_env(char **environ);
t_data				*build_data();
int					count_env(t_llist *env);
int					parser_data(t_llist *env, char **line, t_data **data,
						t_memory **memory);
char				*search_env(t_llist *env, const char *value);
char				**init_option(char *opt, char **save, int index);
int					option_ctrl(t_data *data, t_memory *memory, char **line);
void				init_data(t_llist *env, char *line, t_data **data);
int					operator_filters(char *line);

/*builltin*/
int					ft_echo(t_data *data, t_llist *env, t_memory *memory);
int					ft_variable(t_data *data, t_llist *env, t_memory *memory);
int					ft_cd(t_data *data, t_llist *env, t_memory *memory);
int					ft_env(t_data *data, t_llist *env, t_memory *memory);
int					ft_unsetenv(t_data *data, t_llist *env, t_memory *memory);
int					ft_setenv(t_data *data, t_llist *env, t_memory *memory);
int					ft_toexport(t_data *data, t_llist *env, t_memory *memory);
t_llist				*my_setenv();
char				**my_env(t_llist *env);
int					export_var(t_llist **env, char *var, t_data *data);
int					export_var0(t_llist **env, char *var, t_data *data);
int					unenv(char *unset, t_llist *env);
int					env_collapse(t_llist *env, const char *value);
/*memory gestion*/
int					ctrl_var(char *line);
int					my_ctrl(int test);
int					is_bulltin(char *cmd);
char				*bin_checkout(char *line, t_llist *env, t_data *data);
int					define_memory(t_memory *memory, char *line, t_data *data);
void				generate(int c, int c1, int size, t_data *data);

/*free gestion*/
void 				clear_zone(t_data *data);
void				free_d(char **dtab, int lenght);

int			quote_mode(t_data *data, t_memory *memory, char **line);
#endif
