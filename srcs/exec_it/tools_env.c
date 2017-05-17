/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:39:18 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 03:39:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

char			*search_env(t_llist *env, const char *value)
{
	t_llist		*ptr;

	ptr = env;
	while (ptr != NULL)
	{
		if ((ft_findstr(ptr->content, (char*)value)) == 1)
			return (ptr->content + ft_strchr(ptr->content, '='));
		ptr = ptr->next;
	}
	return (NULL);
}

void			free_mai(t_llist **env, t_llist *ptr, t_llist *sb, t_llist *s)
{
	if (sb == NULL)
	{
		free(ptr->content);
		free(ptr);
		if (s != NULL)
			(*env) = s;
		else
			*env = NULL;
		return ;
	}
	if (s != NULL && sb != NULL)
		sb->next = s;
	else if (s == NULL && sb)
		sb->next = NULL;
	free(ptr->content);
	free(ptr);
}

void			clear_env(t_llist **env, const char *value, int *lenght)
{
	t_llist			*ptr;
	t_llist			*save;
	t_llist			*saveb;

	ptr = *env;
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

static t_llist	*constuct_env(char **environ)
{
	t_llist	*ret;
	char	*new;
	char	*new1;
	int		pos;

	ret = NULL;
	while (*environ)
	{
		if (!(ft_strncmp("SHLVL=", *environ, ft_strlen("SHLVL="))))
		{
			pos = 6;
			new1 = ft_itoa(ft_atoi(*environ + 6) + 1);
			new = ft_strjoin("SHLVL=", new1);
			ft_lstadd(&ret, ft_lstnew(new, ft_strlen(new)));
			free(new);
			free(new1);
		}
		else
			ft_lstadd(&ret, ft_lstnew(*environ, ft_strlen(*environ)));
		environ++;
		g_memory.env_lenght++;
	}
	return (ret);
}

t_llist			*build_env(char **environ)
{
	t_llist	*ret;
	char	*tmp;

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
	else
		return (constuct_env(environ));
	return (NULL);
}
