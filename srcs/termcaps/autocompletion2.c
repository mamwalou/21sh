/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 09:29:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 16:49:47 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "shell.h"
#include "lexer_parser.h"

void				remove_autc(t_autocmp *autocmp)
{
	t_llist			*save;
	t_llist			*ptr;

	ptr = autocmp->match;
	while (ptr)
	{
		save = ptr;
		ptr = ptr->next;
		free(save->content);
		free(save);
	}
}

void				rsearch(char *str, char *trep, t_win *win, t_autocmp *autc)
{
	struct dirent	*files;
	DIR				*rep;

	autc->max_word = 0;
	if (!(rep = opendir(trep)))
		return ;
	while ((files = readdir(rep)) != NULL)
	{
		if (!ft_strncmp(str, files->d_name, ft_strlen(str)))
		{
			autc->occurance++;
			ft_lstadd(&(autc)->match, ft_lstnew(files->d_name,
						ft_strlen(files->d_name)));
		}
	}
	closedir(rep);
}

void				auto_push(char *str, t_win *win, int pos)
{
	while (str[pos])
	{
		push_line(win, str[pos]);
		pos++;
	}
}

void				aff_auto(t_autocmp *autocmpl, t_win *win)
{
	int				count;
	t_llist			*ptr;

	count = 0;
	ptr = autocmpl->match;
	move_cursr(win, M_DOWN, 1);
	while (ptr)
	{
		ft_putstr(ptr->content);
		if (ptr->next != NULL)
			ft_putstr("  ");
		if (count >= g_term.apt.ws_row)
		{
			move_cursr(win, M_DOWN, 1);
			count = 0;
		}
		count += ft_strlen(autocmpl->match->content);
		ptr = ptr->next;
	}
	move_cursr(win, M_DOWN, 1);
	prompt();
	printline(win->begin);
}
