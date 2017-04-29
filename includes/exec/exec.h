/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:45:53 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 10:29:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H
# include "../../includes/ast/ast.h"

typedef enum			s_code
{
	NONE,
	CD_FILES,
	CD_ARG,
	CD_CMD,
}						t_code;

typedef struct			s_exec
{
	t_token				token;
	int					(*f)(t_node *, int *);
}						t_exec;

typedef struct			s_pipe
{
	int					count;
	int					last;
	pid_t				*list;
}						t_pipe;

char					**get_in_env(t_llist *env, const char *str);
t_code					find_command(char **cmd);
t_code					ctrl_arg(char **cmd, int *pos);

/*exec_block*/
int		         		pipe_function(t_node *ast, int *status);
int						logique_fonction(t_node *ast, int *status);
int						redirection_fonction(t_node *ast, int *status);
int						open_files(t_node *ast, int *status);
int						exec_fct(t_node *ast, int *status);
int		 				open_fd(t_node *ast, int *status);

/*pipe_function*/
pid_t					exec_right_pipe(t_pipe *pipe, t_node *right, int fd[2]);
pid_t					exec_left_pipe(t_pipe *pipe, t_node *left, int fd[2]);
void 					new_pid(t_pipe *pipe, pid_t pid);
pid_t					verif_pid(t_pipe *pipe);

/*builltin*/
char					*create_var_env(t_llist *env, char *sigle, char *var);
void					ft_get_pwd(void);
void					ft_cd(char **cmd, int index);

void					ft_setenv(char **cmd);
void					history(char **cmd);

void					ft_unsetenv(char *name);
void					ft_echo(char **cmd);
void					print_env(void);

#endif