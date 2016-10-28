/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	aff_var(t_llist *env, char *ptr)
{
	char	**dword;
	int		lenght;
	int		i;
	char	*tmp;

	i = 0;
	lenght = ft_strsplit(&dword, ptr, generate(' ', 0, 2));
	while (i < lenght)
	{
		if (dword[i][0] == '$')
		{
			if ((tmp = search_env(env, dword[i] + 1)) != NULL)
				ft_putstr(tmp);
			else
				ft_putstr(dword[i]);
		}
		else
			ft_putstr(dword[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (SUCCESS);
}

static int	duo_quote(char *line, t_llist *env)
{
	char	*cpy;
	int		i;
	int		len;
	int		lock;

	i = 0;
	len = 0;
	lock = 0;
	while (line[i])
	{
		if (line[i] != 34)
			len++;
		if (line[i] == '$')
			lock = 1;
		i++;
	}
	cpy = ft_strndup(line, 0, len);
	if (lock)
		return (aff_var(env, cpy));
	else
		ft_putendl(cpy);
	return (SUCCESS);
}

int			parser_echo(t_data *data, t_memory *memory, t_llist *env)
{
	char	*ptr;
	int		i;

	i = 1;
	ptr = memory->line + 5;
	if (*ptr == 34)
		return (duo_quote(ptr + 1, env));
	if (ft_strrchr(ptr, '$'))
		return (aff_var(env, ptr));
	else if (*ptr == 39)
	{
		while (ptr[i])
		{
			if (!ptr[i + 1])
			{
				ft_putchar('\n');
				return (SUCCESS);
			}
			ft_putchar(ptr[i]);
			i++;
		}
	}
	ft_putendl(ptr);
	return (SUCCESS);
}

int			ft_echo(t_data *data, t_llist *env, t_memory *memory)
{
	int		i;

	i = 1;
	if (data->index == 1)
	{
		ft_putchar('\n');
		return (SUCCESS);
	}
	return (parser_echo(data, memory, env));
	return (SUCCESS);
}
