/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:39:18 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/25 12:46:20 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char					*search_env(t_llist *env, const char *value)
{
	t_llist				*ptr;

	ptr = env;
	while (ptr != NULL)
	{
		if ((ft_findstr(ptr->content, (char*)value)) == 1)
			return (ptr->content + ft_strchr(ptr->content, '='));
		ptr = ptr->next;
	}
	return (NULL);
}

void					clear_env(t_llist **env, const char *value)
{
	t_llist				*ptr;
	t_llist				*save;

	ptr = *env;
	save = ptr->next;
	if ((ft_findstr(ptr->content, (char*)value)) == 1)
	{
		free(ptr);
		*env = save;
		(*env)->next = NULL;
	}
	while (ptr->next != NULL)
	{
		if ((ft_findstr(ptr->next->content, (char*)value)) == 1)
		{
			save = ptr->next->next;
			free(ptr->next->content);
			free(ptr->next);
			ptr->next = save;
		}
		ptr = ptr->next;
	}
}

t_llist					*build_env(char **environ)
{
	t_llist				*ret;
	char				*tmp;
	int					lenght;

	lenght = 0;
	ret = NULL;
	if (!*environ)
	{
		tmp = ft_strjoin("TERM=", "xterm-256color");
		ft_putendl_fd("Shell , may not be effective", 2);
		ft_lstadd(&ret, ft_lstnew(tmp, ft_strlen(tmp)));
		g_memory.env_lenght = 1;
		free(tmp);
	}
	while (*environ)
	{
		ft_lstadd(&ret, ft_lstnew(*environ, ft_strlen(*environ)));
		environ++;
		g_memory.env_lenght++;
	}
	return (ret);
}
