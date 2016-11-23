/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"

t_llist				*created_path(int *tabulation, t_llist *e, char *value)
{
	DIR				*ptr;
	struct dirent	*fl;
	t_llist			*ret;
	int				lenght;

	ret = 0;
	if ((ptr = opendir(value)) == NULL)
		exit(1);
	while ((fl = readdir(ptr)) != NULL)
	{
		lenght = ft_strlen(fl->d_name);
		if (fl->d_name[0] != '.')
			ft_lstadd(&ret, ft_lstnew(fl->d_name, lenght));
		if (lenght > *tabulation)
			*tabulation = lenght;
	}
	return (ret);
}

char				*real_push(char *str, char c)
{
	char			*tmp;
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(str);
	tmp = (char*)ft_memalloc(len + 2);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(str);
	return (tmp);
}

void				push_line(char c, t_memory *memo, t_win *win)
{
	win->x++;
	ft_putchar(c);
	if (memo->line == NULL)
	{
		memo->line = (char*)ft_memalloc(1);
		memo->line[0] = c;
		memo->line[1] = '\0';
	}
	else
		memo->line = real_push(memo->line, c);
}

char				*depushline(char *line, t_win *win)
{
	int				i;
	char			*ret;

	if ((ret = (char*)ft_memalloc(win->x + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < win->x)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char				*parsing_term(int code, char *line, t_win *win)
{
	return (line);
}
