/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/minishell.h"

int					count_line(char *s, int lenght, char **ptr)
{
	int				ret;
	int				i;

	ret = 0;
	i = 0;
	lenght--;
	while (s[i] == ' ' && s[i])
		i++;
	while (s[i])
	{
		*ptr = &s[i];
		while ((ft_isalnum(s[i]) || my_ctrl(s[i])) && s[i])
			i++;
		if (s[i] == ' ' || !s[i])
		{
			while (s[i] == ' ')
				i++;
			ret++;
		}
	}
	return (ret);
}

int					putwithtab(char *line, int space)
{
	int				erg;
	int				lght;

	lght = ft_strlen(line);
	erg = space - lght;
	ft_putstr(line);
	while (erg-- != 0)
		ft_putchar(' ');
	return (space - lght + ft_strlen(line));
}

void				list_files(t_win *win, t_llist *dline, int tabulation)
{
	int				count;
	int				lenght_line;

	count = 1;
	lenght_line = 0;
	ft_putchar('\n');
	tputs(tgetstr("sc", NULL), 1, ft_puts);
	while (dline)
	{
		if (lenght_line >= win->column - 20)
		{
			move_cursr(win, CDOWN, 1);
			lenght_line = 0;
			count++;
		}
		lenght_line += putwithtab(dline->content, tabulation);
		dline = dline->next;
	}
	tputs(tgetstr("rc", NULL), 1, ft_puts);
	move_cursr(win, CUP, count);
	move_cursr(win, CRIGHT, win->pos[0] + 1);
}

void				path_found(t_win *win, t_llist *e, char *line, char *lw)
{
	t_llist			*dline;
	char			*save;
	char			*path;
	int				tabulation;

	dline = NULL;
	tabulation = 0;
	path = NULL;
	if (lw == NULL)
		dline = created_path(&tabulation, e, search_env(e, "PWD="));
	else
	{
		if ((is_dir(ft_strtrijoin(search_env(e, "PWD="), "/", lw))) == REP)
		{
			path = ft_strtrijoin(search_env(e, "PWD="), "/", lw);
			dline = created_path(&tabulation, e, path);
			free(path);
			list_files(win, dline, tabulation);
			return ;
		}
	}
	list_files(win, dline, tabulation);
}

int					ft_search(t_win *win, t_llist *e, char *line, t_memory *mem)
{
	int				cptr;
	char			*last_word;

	cptr = 0;
	if (win->lineshell == 0)
		return (0);
	if ((cptr = count_line(line, win->lineshell, &last_word)) > 0)
	{
		if (cptr == 1 && line[win->lineshell - 1] == ' ')
			path_found(win, e, line, NULL);
		else if (cptr > 1)
			path_found(win, e, line, last_word);
	}
	return (TAB);
}
