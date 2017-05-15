/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 06:14:28 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void				history_path(void)
{
	char			*tmp;
	char			*tmp2;

	if (search_env(g_env, "HOME="))
	{
		tmp = ft_strtrijoin("HISTORY=", search_env(g_env, "HOME="), "/");
		tmp2 = ft_strjoin(tmp, ".my_history");
		ft_lstadd(&g_env, ft_lstnew(tmp2, ft_strlen(tmp2)));
		g_memory.env_lenght++;
		free(tmp);
		free(tmp2);
	}
}

int					g_nb_hist(void)
{
	char		*line;
	int			fd;
	int			count;

	count = 0;
	fd = open(search_env(g_env, "HISTORY="),
			O_RDONLY | O_CREAT | O_APPEND, 0666);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line)
			ft_strdel(&line);
		count++;
	}
	close(fd);
	return (count);
}

void				init_memory(void)
{
	g_memory.fd_history = 0;
	g_memory.line = NULL;
	g_memory.variable = NULL;
	g_memory.var_lenght = 0;
	g_memory.launch = 0;
	g_memory.mode = SHELL;
	history_path();
	if (is_dir(search_env(g_env, "HISTORY=")) == FILES)
		g_memory.code_history = g_nb_hist();
	else
		g_memory.code_history = 0;
}

static void			write_history(t_memory *memory)
{
	char			*tmp;
	int				fd;

	fd = open(search_env(g_env, "HISTORY="),
			O_WRONLY | O_CREAT | O_APPEND, 0666);
	tmp = ft_itoa(memory->code_history);
	write(fd, tmp, ft_strlen(tmp));
	write(fd, ";", 1);
	write(fd, memory->line, ft_strlen(memory->line));
	write(fd, "\n", 1);
	free(tmp);
	memory->code_history++;
}

void				push_history(void)
{
	if (g_memory.line)
	{
		if (search_env(g_env, "HISTORY="))
			write_history(&g_memory);
	}
}
