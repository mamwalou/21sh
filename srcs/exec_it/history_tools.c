/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 23:04:42 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/12 23:04:43 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char			**convert_history(char *path_memory, int lenght)
{
	char		**str;
	char		*line;
	int			fd;
	int			i;

	i = 0;
	line = NULL;
	fd = open(path_memory, O_RDWR | O_CREAT | O_APPEND, 0666);
	str = (char**)malloc(sizeof(char*) * lenght);
	while ((get_next_line(fd, &line)) > 0)
	{
		str[i] = ft_strdup(line);
		if (line)
			ft_strdel(&line);
		i++;
	}

	close(fd);
	return (str);
}
