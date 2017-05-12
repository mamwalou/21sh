/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/23 14:43:41 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/12 18:50:29 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			aff_history(char **history, int lenght)
{
	int			i;

	i = 0;
	if (lenght > 10)
		i = lenght - 10;
	while (i < lenght)
	{
		ft_putendl(history[i]);
		i++;
	}
}

void			history(char **cmd)
{
	char		**history;

	history = convert_history(g_memory.history_path, g_memory.code_history);
	if (!ft_strcmp(cmd[0], "history"))
		aff_history(history ,g_memory.code_history);
	free_d(history, g_memory.code_history);
	free(history);
}
