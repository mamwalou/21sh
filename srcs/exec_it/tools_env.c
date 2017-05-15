/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:39:18 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 06:35:33 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int					find_varibale(char *str, char c)
{
	int				count;

	count = 0;
	while (str[count])
	{
		if (str[count] == c)
			return (1);
		count++;
	}
	return (-1);
}

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

void					clear_env(t_llist **env, const char *value, int *lenght)
{
	t_llist				*ptr;
	t_llist				*save;
	t_llist				*saveb;

	ptr = *env;
	save = NULL;
	saveb = NULL;
	while (ptr)
	{
		if (ptr->next != NULL)
			save = ptr->next;
		else
			save = NULL;
		if (!ft_strncmp(ptr->content, value, ft_strlen(value)))
		{
			free_mai(env, ptr, saveb, save);
			*lenght -= 1;
			return ;
		}
		saveb = ptr;
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
		return (ret);
	}
	while (*environ)
	{
		ft_lstadd(&ret, ft_lstnew(*environ, ft_strlen(*environ)));
		environ++;
		g_memory.env_lenght++;
	}
	return (ret);
}
