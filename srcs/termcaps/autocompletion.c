/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 09:28:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 07:55:10 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"
#include "../../includes/lexer_parser/lexer_parser.h"

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

void				sawfolder(t_win *win, char *path, t_autocmp *autc)
{
	struct dirent	*files;
	DIR				*rep;

	autc->max_word = 0;
	if (!(rep = opendir(path)))
		return ;
	while ((files = readdir(rep)) != NULL)
	{
		autc->occurance++;
		ft_lstadd(&(autc)->match, ft_lstnew(files->d_name,
					ft_strlen(files->d_name)));
	}
	if (win->end->l_char != '/')
		push_line(win, '/');
	closedir(rep);
}

void				folder_search(char *str, t_win *win, t_autocmp *autocmpl)
{
	char			*path;
	int				i;

	i = 0;
	path = NULL;
	if (is_dir(str) == REP)
		sawfolder(win, str, autocmpl);
	else
	{
		if (!(path = search_env(g_env, "PWD=")))
			return ;
		rsearch(str, path, win, autocmpl);
	}
	if (autocmpl->occurance == 1)
		auto_push(autocmpl->match->content, win, ft_strlen(str));
	else if (autocmpl->occurance > 1)
		aff_auto(autocmpl, win);
}

void				binary_search(char *str, t_win *win, t_autocmp *autocmpl)
{
	int				lenght;
	char			**path;
	int				*tableau;
	int				i;

	i = 0;
	tableau = generate(58, 0, 2);
	lenght = ft_strsplit(&path, search_env(g_env, "PATH="), tableau);
	while (i < lenght - 1)
	{
		rsearch(str, path[i], win, autocmpl);
		i++;
	}
	if (autocmpl->occurance == 1)
		auto_push(autocmpl->match->content, win, ft_strlen(str));
	else if (autocmpl->occurance > 1)
		aff_auto(autocmpl, win);
	free(tableau);
	free_d(path, lenght);
	free(path);
}

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

static void 		gestion_auto(t_autocmp *autocmpl, t_win *win, char **tmp2)
{
	if (autocmpl->lenght > 1 &&((!operator_filters(tmp2[autocmpl->lenght - 1]) &&
		!redirection_filters(tmp2[autocmpl->lenght - 1]))))
		folder_search(tmp2[autocmpl->lenght - 1], win, autocmpl);
	else
		binary_search(tmp2[autocmpl->lenght - 1], win, autocmpl);
}

int					autocompletion(t_win *win)
{
	t_autocmp		autocmpl;
	char			**tmp2;
	char			*tmp;
	int				*tableau;

	tmp = NULL;
	tmp2 = NULL;
	autocmpl.match = NULL;
	autocmpl.occurance = 0;
	if (!search_env(g_env, "PATH="))
		return (1);
	tmp = lchar_list(win->begin, win->lenght_line);
	tableau = generate(9, 32, 3);
	if ((autocmpl.lenght = ft_strsplit(&tmp2, tmp, tableau)) > 0)
	{
		ft_putnbr(autocmpl.lenght);
		gestion_auto(&autocmpl, win, tmp2);
		remove_autc(&autocmpl);
		free_d(tmp2, autocmpl.lenght);
		free(tmp2);
	}
	free(tableau);
	free(tmp);
	return (1);
}
