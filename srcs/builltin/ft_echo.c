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

static void aff_echo(char *ptr)
{
	while (*ptr)
	{
		ft_putchar(*ptr);
		ptr++;
	}
	ft_putchar('\n');
}
static int	duo_quote(char *line, t_llist *env, int len)
{
	char	*cpy;
	int		i;
	int		lock;

	i = 0;
	lock = 0;
	cpy = ft_strndup(line, 0, len);
	aff_echo(cpy);
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
		return (duo_quote(ptr, env, ft_strchr(ptr, 34)));
	aff_echo(ptr);
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
