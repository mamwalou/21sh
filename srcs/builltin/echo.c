/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:40:37 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/25 03:17:46 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

static void	echo_n_mode(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putchar(tab[i]);
		i++;
	}
	ft_putchar('\n');
}

static void	echo_normal_mode(char *tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putchar(tab[i]);
		i++;
	}
	ft_putchar('\n');

}

void		ft_echo(char **cmd)
{
	if (!cmd[1])
	{
		ft_putchar('\n');
		return ;
	}
	if (ft_strcmp(cmd[1], "-n") == 0)
		echo_n_mode(cmd[1]);
	else if (cmd[1])
		echo_normal_mode(cmd[1]);
}
