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

t_llist				*my_setenv(void)
{
	t_llist			*new_env;
	char			*buf;

	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	ft_lstadd(&new_env, ft_lstnew("NO_ENV=null", 11));
	ft_lstadd(&new_env, ft_lstnew(ft_strjoin("PWD=", buf), ft_strlen(buf) + 4));
	ft_lstadd(&new_env, ft_lstnew(ft_strjoin("OLDPWD=", buf)
				, ft_strlen(buf) + 7));
	return (new_env);
}

int					ft_setenv(t_data *data, t_llist *env, t_memory *memory)
{
	t_llist			*ptr;

	ptr = env;
	if (memory->var && data->index == 1)
		return (export_var(&env, memory->var));
	else if (memory->var && data->index >= 1)
		return (export_var0(&env, memory->var, data->option, data->index));
	else
		return (32);
	return (0);
}
