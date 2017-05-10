/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 14:43:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/07 21:23:55 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			aff_history(void)
{
	char		*line;
	int			fd;

	fd = open(g_memory.history_path, O_RDWR | O_CREAT | O_APPEND, 0666);
	while ((get_next_line(fd, &line)) > 0)
	{
		if (line)
			ft_strdel(&line);
		free(line);
	}
	close(fd);
}

void			history(char **cmd)
{
	if (!ft_strcmp(cmd[0], "history"))
		aff_history();
}
