/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 10:44:20 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void				history_path(void)
{
	char			*home;

	if ((home = search_env(g_env, "HOME=")))
	{
		g_memory.history_path = ft_strtrijoin(home, "/", ".my_history");
		g_memory.fd_history = open(g_memory.history_path,
							O_RDWR | O_CREAT | O_APPEND, 0666);
	}
}

int					g_nb_hist(void)
{
	char		*buf;
	int			fd;
	int			count;

	count = 0;
	fd = open(g_memory.history_path, O_RDWR | O_CREAT | O_APPEND, 0666);
	while ((get_next_line(fd, &buf)) > 0)
	{
		count++;
		free(buf);
	}
	free(buf);
	close(fd);
	return (count);
}

void				init_memory(void)
{
	g_memory.fd_history = 0;
	g_memory.line = NULL;
	g_memory.launch = 0;
	g_memory.mode = SHELL;
	g_memory.history_path = NULL;
	history_path();
	if (is_dir(g_memory.history_path) == FILES)
		g_memory.code_history = g_nb_hist();
	else
		g_memory.code_history = 0;
}

static void			write_history(t_memory *memory)
{
	char			*tmp;

	tmp = ft_itoa(memory->code_history);
	write(memory->fd_history, tmp, ft_strlen(tmp));
	write(memory->fd_history, ";", 1);
	write(memory->fd_history, memory->line, ft_strlen(memory->line));
	write(memory->fd_history, "\n", 1);
	free(tmp);
	memory->code_history++;
}

void				push_history(void)
{
	int				fd;
	char			*home;
	char			*history_path;

	if (g_memory.line)
	{
		if (g_memory.history_path)
			write_history(&g_memory);
	}
}
