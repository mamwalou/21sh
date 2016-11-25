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

void 				push_data(t_data **data)
{
	;
}

void				init_data(t_llist *env, char *line, t_data **data)
{
	char			*blank;

	if ((is_bulltin(line)))
	{
		(*data)->cmd = ft_strdup(line);
		(*data)->option = init_option((*data)->cmd, (*data)->option, (*data)->index);
		(*data)->index += 1;
		return ;
	}
	if (((*data)->cmd = bin_checkout(line, env, (*data))) != NULL)
	{
		(*data)->option = init_option((*data)->cmd, (*data)->option, (*data)->index);
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
