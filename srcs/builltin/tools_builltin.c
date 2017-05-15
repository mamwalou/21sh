/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_builltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:48:42 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 15:10:29 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			replace_env(t_llist **list, char *sigle, char *new, int *lenght)
{
	char		*to_env;

	clear_env(list, sigle, lenght);
	to_env = ft_strjoin(sigle, new);
	ft_lstadd(list, ft_lstnew(to_env, ft_strlen(to_env)));
	*lenght += 1;
	free(to_env);
}

char			**get_in_env(t_llist *env, const char *str)
{
	t_llist		*ptr;
	char		**dstr;
	int			*tab;

	ptr = env;
	tab = generate(':', '=', 3);
	while (ptr && ft_strncmp(ptr->content, str, ft_strlen(str)))
		ptr = ptr->next;
	ft_strsplit(&dstr, ptr->content, tab);
	free(tab);
	return (dstr);
}

char			*create_var_env(char *sigle, char *var)
{
	char		*to_return;

	to_return = ft_strjoin(sigle, var);
	return (to_return);
}
