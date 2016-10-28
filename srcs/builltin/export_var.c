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

static int	f_realloc(t_llist *ptr, char *new)
{
	free(ptr->content);
	ptr->content = ft_strdup(new);
	return (SUCCESS);
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

int			export_var(t_llist **env, char *var)
{
	char		**var_memo;
	t_llist		*ptr;
	int			i;
	int			len;

	i = 0;
	len = ft_strsplit(&var_memo, var, generate(59, 0, 2));
	while (var_memo[i])
	{
		ptr = *env;
		while (ptr)
		{
			if (!ft_strcmp(ptr->content, var_memo[i]))
				return (ER_PREMMR);
			else if (!ft_strncmp(ptr->content, var_memo[i],
						ft_strchr(var_memo[i], '=')))
				return (f_realloc(ptr, var_memo[i]));
			ptr = ptr->next;
		}
		ft_lstadd(env, ft_lstnew(var_memo[i], ft_strlen(var_memo[i])));
		i++;
	}
	if (len)
		free_d(var_memo, len);
	return (0);
}

int			export_var0(t_llist **env, char *var, char **option, int index)
{
	char	**var_memo;
	t_llist	*ptr;
	int		i;
	int		y;

	i = 0;
	ft_strsplit(&var_memo, var, generate(59, 0, 2));
	while (i < index)
	{
		y = 0;
		while (var_memo[y])
		{
			if (!ft_strncmp(option[i], var_memo[y],
					ft_strchr(var_memo[y], '=') - 1))
			{
				if ((overlaps_env(env, var_memo[y])) == ER_PREMMR)
					export_var(env, var_memo[y]);
			}
			y++;
		}
		i++;
	}
	return (SUCCESS);
}
