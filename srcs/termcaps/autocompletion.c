/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 09:28:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 11:08:51 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"
#include "../../includes/lexer_parser/lexer_parser.h"

void				auto_push(char *str, t_win *win, int pos)
{
	while (str[pos])
	{
		push_line(win, str[pos]);
		pos++;
	}
}

void				rsearch(char *str, char *trep, t_win *win, t_autocmp *autc)
{
	struct dirent	*files;
	DIR				*rep;

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
	free_d(path, lenght);
	free(path);
}

void				folder_search(char *str, t_win *win, t_autocmp *autocmpl)
{
	int				lenght;
	char			*path;
	int				i;

	i = 0;
	if (!(path = ft_strdup(search_env(g_env, "PWD="))))
		return ;
	rsearch(str, path, win, autocmpl);
	if (autocmpl->occurance == 1)
		auto_push(autocmpl->match->content, win, ft_strlen(str));
	else if (autocmpl->occurance > 1)
		aff_auto(autocmpl, win);
	if (path)
		free(path);
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
	tmp = lchar_list(win->begin, win->lenght_line);
	tableau = generate(9, 32, 3);
	autocmpl.lenght = ft_strsplit(&tmp2, tmp, tableau);
	if (autocmpl.lenght == 0)
		return (1);
	if (autocmpl.lenght > 1 && ((!operator_filters(tmp2[autocmpl.lenght - 1]) &&
		!redirection_filters(tmp2[autocmpl.lenght - 1]))))
		folder_search(tmp2[autocmpl.lenght - 1], win, &autocmpl);
	else
		binary_search(tmp2[autocmpl.lenght - 1], win, &autocmpl);
	free(tableau);
	ft_lstdel(&(autocmpl).match, ft_bzero);
	free_d(tmp2, autocmpl.lenght);
}
