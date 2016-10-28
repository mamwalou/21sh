/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int				unenv(char *unset, t_llist *env)
{
	t_llist		*ptr;
	t_llist		*save;
	t_llist		*to_next;

	ptr = env;
	if (unset[ft_strlen(unset)] != '=')
		ft_strjoin(unset, "=");
	while (ptr)
	{
		if (!ft_strncmp((const char*)ptr->content, unset, ft_strlen(unset)))
		{
			to_next = ptr->next;
			free(ptr->content);
			free(ptr);
			save->next = to_next;
			return (0);
		}
		save = ptr;
		ptr = ptr->next;
	}
	return (2);
}

int				ft_unsetenv(t_data *data, t_llist *env, t_memory *memory)
{
	if (data->option != NULL)
		return (unenv(data->option[1], env));
	return (45);
}
