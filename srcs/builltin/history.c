/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 14:43:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/25 17:12:38 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void 			aff_history(void)
{
	char		*buf;
	int			fd;

	fd = open(g_memory.history_path, O_RDWR | O_CREAT | O_APPEND, 0666);
	while ((get_next_line(fd, &buf)) > 0)
	{
		ft_putendl(buf);
		free(buf);
	}
	free(buf);
	close(fd);
}
void			history(char **cmd)
{
	if (!ft_strcmp(cmd[0], "history"))
		aff_history();

}
