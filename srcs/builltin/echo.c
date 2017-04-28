/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:40:37 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/14 11:28:44 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			ft_echo(char **cmd)
{
	int			i;

	if (!ft_strcmp(cmd[1], "-n"))
	{
		i = 2;
		while (cmd[i])
		{
			ft_putstr(cmd[i]);
			i++;
		}
	}
	else
	{
		i = 1;
		while (cmd[i])
		{
			ft_putstr(cmd[i]);
			i++;
		}
		ft_putchar('\n');
	}
}
