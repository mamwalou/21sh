/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_history.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/23 15:28:33 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
	ft_bzero(&g_memory, sizeof(t_memory));
	init_term(&g_memory);
	g_memory.mode = SHELL;
	history_path();
	if (is_dir(search_env(g_env, "HISTORY=")) == FILES)
		g_memory.code_history = g_nb_hist();
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
	close(fd);
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
