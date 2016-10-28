/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include <unistd.h>
# include <term.h>
# include <curses.h>
# include <dirent.h>
# include "../../libft/Includes/libft.h"
# include "../minishell.h"

# define ESCAPE      27
# define SPACE       32
# define UP          4283163
# define LEFT        4479771
# define RIGHT       4414235
# define DOWN        4348699
# define RETURN      10
# define DELETE      127
# define BACKSPACE   2117294875
# define HOME        4741915
# define END         4610843
# define PAGEDOWN    2117491483
# define PAGEUP      2117425947
# define CTRL_C      3
# define CTRL_D      4
# define CTRL_L      12
# define CTRL_Z      26
# define CTRL_R      18
# define SHIFT_LEFT  17458
# define SHIFT_RIGHT 17202
# define SHIFT_UP    16690
# define SHIFT_DOWN  16946
# define SHIFT       993090331
# define TAB		 9
# define CTRL_SPACE  0
# define CTRL_X      24
# define CNT_TERM	5
# define CDOWN		98
# define CUP		97
# define CLEFT		96
# define CRIGHT		95
# define JTAB		100

char g_buf[512];
char *g_left;
char *g_clear;
char *g_up;
char *g_down;
char *g_right;
char *g_save;
char *g_reset;
char *g_resline;

typedef struct	s_win
{
	int			begin;
	int			lenght;
	int			column;
	int			lineshell;
	char		*save;
	char		buffer[4];
	int			pos[2];
	int			set;
}				t_win;

typedef struct	s_terminal
{
	int			input;
	int			(*f)(t_win *, t_llist *, char *, t_memory *mem);
}				t_terminal;

int				termcaps(t_llist *env, t_memory *memory, int len, t_win *win);

int				init_varfcurs();

int				ft_puts(int c);
void			bring_back_shell(struct termios *term);

t_llist			*created_path(int *tabulation, t_llist *e, char *value);
char			*parsing_term(int code, char *line, t_win *win);
char			*depushline(char *line, t_win *win);
char			*push_line(char c, char *line, t_win *win);
char			*tabulation(char *line, t_win *win);
int				termc_ctrl(char *l, t_win *w, t_llist *e, t_memory *mem);

int				ft_space(t_win *win, t_llist *e, char *line, t_memory *mem);
int				ft_del(t_win *win, t_llist *e, char *line, t_memory *mem);
int				ft_search(t_win *win, t_llist *e, char *line, t_memory *mem);
int				ft_clear(t_win *win, t_llist *e, char *line, t_memory *mem);
int				ft_signal(t_win *win, t_llist *e, char *line, t_memory *mem);

void			move_cursr(t_win *win, int mode, int iteration);

#endif
