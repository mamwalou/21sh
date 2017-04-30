/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/29 13:30:34 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMCAPS_H
# define TERMCAPS_H

# include <unistd.h>
# include <term.h>
# include <curses.h>
# include <dirent.h>
# include <signal.h>
# include "../../libft/Includes/libft.h"
# include "../shell.h"

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
# define CTRL_D      4
# define CTRL_L      12
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

typedef enum 			s_iter
{
	DELETING,
	PUSH,
	M_UP,
	M_RIGHT,
	M_DOWN,
	M_LEFT,
	M_DEL,
}						t_iter;

typedef struct			s_line
{
	uint64_t			l_char;
	struct s_line		*next;
	struct s_line		*prev;
}						t_line;

typedef struct			s_win
{
	int					y;
	int					x;
	int					lenght_line;
	int					cursor_line;
	int					pos_history;
	char				buffer[BUFF_SIZE];
	char				**hst;
	t_line				*begin;
	t_line				*end;
}						t_win;


typedef struct			s_input
{
	int					input;
	void				(*f)(t_win *win);
}						t_input;

typedef	struct			s_term
{
	struct termios 		terminal;
	struct termios 		new_term;
	struct winsize		apt;
	int					lock;
}						t_term;

t_term					g_term;


void			termcaps(void);
int				ft_puts(int c);
void			bring_back_shell(struct termios *term);
int				init_term(struct termios *term);
void 			read_display(t_win *win);

/*MODE*/
t_mode			shell_mode(t_win *win);
t_mode			hered_mode(t_win *win);
t_mode			quote_mode(t_win *win);
t_mode			d_quote_mode(t_win *win);
int				stop_her(t_line *end);
int				stoq(t_line *end, int key);
void			depushline(t_win *win);
void			push_line(t_win *win, unsigned int buffer);

void			printline(t_line *begin);
void			line_init(t_line **begin, t_line **end, t_win *win);

/*signaux*/
void			handl_sig(void);

/*input*/
void			input(t_win *win);

char			*tabulation(char *line, t_win *win);
void			autocompletion(t_win *win);

/*cursor*/
void			move_cursr(t_win *win, t_iter iter, int iteration);
void			gest_crs(t_win *win);
void			history_termcaps(t_win *win);
void			dhistory_termcaps(t_win *win);

/*list_to_array*/
void 			list_to_array(t_win *win);
void			list_lchar(char *str, t_win *win);
char			*lchar_list(t_line *line, int lenght);

#endif
