/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/12/01 15:27:59 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int				unenv(char *unset, t_llist *env)
{
	t_llist		*ptr;
	t_llist		*save;
	t_llist		*to_next;

	ptr = env;
	if (unset[ft_strlen(unset)] != '=')
		unset = ft_strjoin(unset, "=");
	while (ptr)
	{
		if (!ft_strncmp((const char*)ptr->content, unset, ft_strlen(unset)))
		{
			to_next = ptr->next;
			free(ptr->content);
			free(ptr);
			save->next = to_next;
			free(unset);
			return (0);
		}
		save = ptr;
		ptr = ptr->next;
	}
	free(unset);
	return (2);
}

int				ft_unsetenv(t_data *data, t_llist *env, t_memory *memory)
{
	if (data->option != NULL)
		return (unenv(data->option[1], env));
	return (45);
}
