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

	lenght = ft_strsplit(&path, search_env(g_env, "PATH="), generate(58, 0, 2));
	while (lenght--)
		rsearch(str, path[lenght], win, autocmpl);
	free_d(path);
}

void				autocompletion(t_win *win)
{
	t_autocmp		autocmpl;
	char			*tmp;
	char			**tmp2;
	int				lenght;

	autocmpl.match = NULL;
	autocmpl.occurance = 0;
	tmp = lchar_list(win->begin, win->lenght_line);
	lenght = ft_strsplit(&tmp2, tmp, generate(9, 32, 3));
	if (lenght == 1 || operator_filters(tmp2[lenght - 2]) > 0
		|| redirection_filters(tmp2[lenght - 2]) > 0)
		binary_search(tmp2[lenght - 1], win, &autocmpl);
	else
		rsearch(tmp2[lenght - 1], search_env(g_env, "PWD="), win, &autocmpl);
	if (autocmpl.occurance == 1)
		auto_push(autocmpl.match->content, win, ft_strlen(tmp2[lenght - 1]));
	else if (autocmpl.occurance > 1)
		aff_auto(&autocmpl, win);
	ft_lstdel(&(autocmpl).match, ft_bzero);
	free_d(tmp2);
}
