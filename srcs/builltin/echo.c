/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:40:37 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 20:31:08 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			ft_echo(char *cmd)
{
	int			count;

	count = 4;
	while (cmd[count] && cmd[count] == ' ')
		count++;
	if (cmd[count] == '-' && cmd[count + 1] == 'n')
		count += 2;
	while(cmd[count])
	{
		ft_putchar(cmd[count]);
		count++;
	}
	ft_putchar('\n');
	return ;
}
