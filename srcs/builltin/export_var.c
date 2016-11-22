/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	f_env_realloc(t_llist *ptr, char *new, int pos)
{
	int 	i;

	i = 1;
	while (i++ < pos)
		ptr = ptr->next;
	free(ptr->content);
	ptr->content = ft_strdup(new);
}

int			overlaps_env(t_llist **env, char *var_memo)
{
	t_llist *ptr;

	ptr = *env;
	while (ptr)
	{
		if (!ft_strcmp(ptr->content, var_memo))
			return (ER_PREMMR);
		else if (!ft_strncmp(ptr->content, var_memo, ft_strchr(var_memo, '=')))
		{
			free(ptr->content);
			ptr->content = ft_strdup(var_memo);
			return (SUCCESS);
		}
		ptr = ptr->next;
	}
	return (ER_PREMMR);
}

int			export_var(t_llist **env, char *var, t_data *data)
{
	char		**var_memo;
	int			len;
	int			pos;
	int			i;

	i = 0;
	generate(59, 0, 2, data);
	len = ft_strsplit(&var_memo, var, data->tableau);
	while (i < len)
	{
		if ((search_env(*env, var_memo[i] + 1)) != NULL)
			return (ER_PREMMR);
		else if ((pos = env_collapse(*env, var_memo[i])))
			f_env_realloc(*env, var_memo[i], pos);
		else
			ft_lstadd(env, ft_lstnew(var_memo[i], ft_strlen(var_memo[i])));
		i++;
	}
	free_d(var_memo, len);
	return (0);
}
