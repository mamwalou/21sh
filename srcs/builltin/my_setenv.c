/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_llist				*build_env(char **environ)
{
	t_llist			*ret;

	ret = NULL;
	while (*environ)
	{
		ft_lstadd(&ret, ft_lstnew(*environ, ft_strlen(*environ)));
		environ++;
	}
	return (ret);
}

int					ft_setenv(t_data *data, t_llist *env, t_memory *memory)
{
	t_llist			*ptr;

	ptr = env;
	if (!ft_strcmp(data->cmd, "setenv"))
		return (export_var(&env, data->option[1], data));
	else if (memory->var)
		return (export_var(&env, memory->var, data));
	return (0);
}
