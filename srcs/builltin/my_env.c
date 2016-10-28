/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				count_env(t_llist *env)
{
	t_llist		*ptr;
	int			ret;

	ptr = env;
	ret = 0;
	while (ptr)
	{
		ptr = ptr->next;
		ret++;
	}
	return (ret);
}

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

char			**my_env(t_llist *env)
{
	t_llist		*ptr;
	char		**ret;
	int			count;

	count = 0;
	ptr = env;
	while (ptr->next != NULL)
		ptr = ptr->next;
	ret = (char**)malloc(sizeof(char*) * ptr->maillon_nb + 1);
	ptr = env;
	while (ptr)
	{
		ret[count] = ft_strdup(ptr->content);
		count++;
		ptr = ptr->next;
	}
	ret[count] = "\0";
	return (ret);
}

int				ft_env(t_data *data, t_llist *env, t_memory *memory)
{
	t_llist		*ptr;

	ptr = env;
	if (data->option[1] && !ft_strcmp(data->option[1], "-i"))
	{
		ft_lstdel(&env, ft_bzero);
		return (-7);
	}
	while (ptr)
	{
		ft_putendl(ptr->content);
		ptr = ptr->next;
	}
	return (0);
}

int				ft_toexport(t_data *data, t_llist *env, t_memory *memory)
{
	if (memory->var)
		ft_putendl(memory->var);
	else
		ft_putendl("no variable set");
	return (0);
}
