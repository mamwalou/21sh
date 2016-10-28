/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char		*rewirte(char **array, char *line, int pos, int len)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (i < len)
	{
		if (i != pos)
		{
			if (ret)
				ret = ft_strtrijoin(array[i], ";", ret);
			else
				ret = ft_strdup(array[i]);
		}
		i++;
	}
	if (ret)
		ret = ft_strtrijoin(ret, ";", line);
	else
		ret = ft_strdup(line);
	return (ret);
}

int			overlaps(t_memory *memory, char **array, char *line, int len)
{
	int		pos;
	int		count;

	count = 0;
	pos = ft_strchr(line, '=');
	while (array[count])
	{
		if (!ft_strncmp(array[count], line, pos))
			if (ft_strcmp(array[count], line))
			{
				memory->var = rewirte(array, line, count, len);
				return (1);
			}
		count++;
	}
	return (0);
}

int			can_var(t_memory *memory, char *line)
{
	char	**array;
	int		i;
	int		len;

	i = 0;
	len = ft_strsplit(&array, memory->var, generate(';', 0, 2));
	while (array[i])
	{
		if (!ft_strcmp(line, array[i]))
			return (7);
		i++;
	}
	if (!overlaps(memory, array, line, len))
		memory->var = ft_strtrijoin(memory->var, ";", line);
	return (7);
}

int			define_variable(t_memory *memory, char *line)
{
	char			**cpy;

	if (memory->var)
		return (can_var(memory, line));
	else
		memory->var = ft_strdup(line);
	return (6);
}
