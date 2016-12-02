/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/12/01 15:28:01 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static int		concat_var(char *test_to_env, t_llist *env)
{
	char		*tmp;
	char		*str;
	int			i;

	i = 0;
	while (test_to_env[i] != ' ' && test_to_env[i])
		i++;
	tmp = ft_strndup(test_to_env, 1, i);
	if ((str = search_env(env, tmp)) != NULL)
	{
		ft_putstr(str);
		free(tmp);
		return (i + 1);
	}
	free(tmp);
	return (0);
}

static void 	aff_echo(char *ptr, t_llist *env)
{
	int			save;

	save = 0;
	while (*ptr)
	{
		if (*ptr == '$')
		{
			if ((save = concat_var(ptr, env)))
				ptr = ptr + save;
		}
		if (*ptr)
			ft_putchar(*ptr);
		ptr++;
	}
	ft_putchar('\n');
}

static int		duo_quote(char *line, t_llist *env, int len)
{
	char		*cpy;
	int			i;
	int			lock;

	i = 0;
	lock = 0;
	if (len == 0)
		return (QUOTE_OPT);
	cpy = ft_strndup(line, 1, len);
	aff_echo(cpy, env);
	free(cpy);
	return (SUCCESS);
}

int			parser_echo(t_memory *memory, t_llist *env)
{
	char	*ptr;
	int		i;

	i = 1;
	ptr = (memory->line) + 5;
	while (*ptr == ' ')
		ptr++;
	if (*ptr == 34)
		return (duo_quote(ptr, env, ft_strchr(ptr + 1, 34)));
	aff_echo(ptr, env);
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
	return (parser_echo(memory, env));
}
