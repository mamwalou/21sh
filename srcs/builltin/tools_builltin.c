/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_builltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:48:42 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 12:51:56 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

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

char			*ctrl_access(char **path, char *name, int ctrl_type)
{
	char		*tmp;
	int			count;

	count = 0;
	while (path[count])
	{
		tmp = ft_strtrijoin(path[count], "/", name);
		if (access(tmp, X_OK) == 0)
		{
			free_d(path);
			free(path);
			return (tmp);
		}
		free(tmp);
		count++;
	}
	free_d(path);
	free(path);
	return (NULL);
}

t_code			find_command(char **cmd)
{
	char		*tmp;

	tmp = NULL;
	if (is_bulltin(*cmd))
		return (NONE);
	if (access(*cmd, X_OK) == 0)
		return (NONE);
	if ((tmp = ctrl_access(get_in_env(g_env, "PATH="),
		*cmd, 0)) == NULL)
	{
		ft_putstr_fd("shell: command not found: ", 2);
		ft_putendl_fd(*cmd, 2);
		free(tmp);
		return (CD_CMD);
	}
	else
	{
		free(*cmd);
		*cmd = ft_strdup(tmp);
		free(tmp);
	}
	return (NONE);
}

char			*create_var_env(t_llist *env, char *sigle, char *var)
{
	char		*to_return;

	to_return = ft_strjoin(sigle, var);
	return (to_return);
}
