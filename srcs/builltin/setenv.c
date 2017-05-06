/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:37:46 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 10:42:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			ft_setenv(char *name, char *value)
{
	char		*str;

	str = NULL;
	if (!name || !value)
	{
		ft_putendl_fd("Wrong set of env", 2);
		return ;
	}
	if ((search_env(g_env, name)) != NULL)
	{
		ft_putendl_fd(name, 2);
		ft_putendl_fd("already set", 2);
		return ;
	}
	str = ft_strtrijoin(name, "=", value);
	ft_lstadd(&g_env, ft_lstnew(str, ft_strlen(str)));
	free(str);
}

void			ft_unsetenv(char *name)
{
	clear_env(&g_env, name);
}
