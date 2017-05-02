/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_builltin2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:47:11 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 12:19:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

t_code				ctrl_arg(char **cmd, int *pos)
{
	int				test;

	test = 0;
	while (cmd[*pos])
	{
		if (cmd[*pos][0] != '-')
		{
			test = is_dir(cmd[*pos]);
			if (test != FILES && test != REP)
			{
				ft_putstr_fd("shell: No such file or directory: ", 2);
				ft_putendl_fd(cmd[*pos], 2);
				return (CD_FILES);
			}
		}
		*pos += 1;
	}
	return (NONE);
}
