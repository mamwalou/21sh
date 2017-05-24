/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hst_retrieve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 00:39:58 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/24 02:18:55 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	hst_retrieve(t_memory *sh)
{
	char		*line;
	char		*cmd;
	int			fd;

	fd = open(search_env(g_env, "HISTORY="), O_RDONLY | O_CREAT, 0666);
	line = NULL;
	while (get_next_line(fd, &line) > 0)
	{
		if (line)
		{
			if ((cmd = ft_strchr(line, ';')) != NULL && *(cmd + 1) != 0)
				hst_push(sh, line);
			ft_strdel(&line);
		}
		sh->code_history++;
	}
	close(fd);
}
