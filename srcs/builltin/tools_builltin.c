/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_builltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:48:42 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 07:44:14 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void 		free_mai(t_llist **env,t_llist *ptr, t_llist *saveb, t_llist *save)
{
	if (saveb == NULL)
	{
		free(ptr->content);
		free(ptr);
		if (ptr->next != NULL)
			(*env)->next = save;
		else
			*env = NULL;
		return ;
	}
	if (save != NULL && saveb != NULL)
		saveb->next = save;
	else if (save == NULL && saveb)
		saveb->next = NULL;
	free(ptr->content);
	free(ptr);
}

void			replace_env(t_llist *list, char *sigle, char *new, int *lenght)
{
	char		*to_env;

	clear_env(&list, sigle, lenght);
	to_env = ft_strjoin(sigle, new);
	ft_lstadd(&list, ft_lstnew(to_env, ft_strlen(to_env)));
	g_memory.env_lenght++;
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
