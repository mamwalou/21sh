/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_gest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/12/05 14:13:02 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

void		free_d(char **dtab, int lenght)
{
	int		i;

	i = 0;
	while (i < lenght)
	{
		free(dtab[i]);
		i++;
	}
	free(dtab);
}
/*
void 		clear_zone(t_data *data)
{
	int i;

	i = 0;
	if (data->tableau)
		free(data->tableau);
	if (data->cmd)
		free(data->cmd);
	if (data->option)
	{

		while(data->option[i])
		{
			i++;
		}
		free_d(data->option, i);
	}
	if (data->operation)
		free(data->operation);
	free(data);
}
*/
