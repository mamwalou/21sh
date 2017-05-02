/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 09:25:59 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 10:39:07 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char			**convert_history(char *path_memory, int lenght)
{
	char		**str;
	char		*buf;
	int			fd;
	int			i;

	i = 0;
	fd = open(path_memory, O_RDONLY | O_CREAT | O_APPEND, 0666);
	str = (char**)ft_memalloc(sizeof(char*) * lenght);
	while ((get_next_line(fd, &buf)) > 0)
	{
		str[i] = ft_strdup(buf);
		free(buf);
		i++;
	}
	str[i] = 0;
	free(buf);
	close(fd);
	return (str);
}
