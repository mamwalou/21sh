/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:04:42 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/14 10:58:08 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char			**convert_history()
{
	char		**str;
	char		*line;
	int			fd;
	int			i;

	i = 0;
	line = NULL;
	fd = open(search_env(g_env, "HISTORY="), O_RDWR | O_CREAT | O_APPEND, 0666);
	str = (char**)malloc(sizeof(char*) * g_memory.code_history);
	while ((get_next_line(fd, &line)) > 0)
	{
		str[i] = ft_strdup(line);
		if (line)
			ft_strdel(&line);
		i++;
	}
	if (line)
		ft_strdel(&line);
	close(fd);
	return (str);
}
