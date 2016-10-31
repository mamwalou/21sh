/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void				init_data(t_llist *env, char *line, t_data **data)
{
	char			*blank;

	if (((*data)->cmd = is_bulltin(line)) != NULL)
	{
		(*data)->index += 1;
		(*data)->option = init_option((*data)->cmd, (*data)->option);
		return ;
	}
	if (((*data)->cmd = bin_checkout(line, env, (*data))) != NULL)
	{
		(*data)->index += 1;
		(*data)->option = init_option((*data)->cmd, (*data)->option);
		(*data)->index = 0;
		return ;
	}
}

t_data				*build_data(void)
{
	t_data			*data;

	data = (t_data*)ft_memalloc(sizeof(t_data));
	data->index = 0;
	data->cmd = 0;
	data->tableau = 0;
	data->option = NULL;
	data->operation = NULL;
	data->left = NULL;
	data->right = NULL;
	return (data);
}
