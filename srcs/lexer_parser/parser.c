/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int			*generate(int c, int c1, int size)
{
	int		*tableau;

	tableau = (int*)ft_memalloc(sizeof(int) * size);
	if (size == 2)
	{
		tableau[0] = c;
		tableau[1] = 0;
		tableau[2] = 0;
	}
	if (size == 3)
	{
		tableau[0] = c;
		tableau[1] = c1;
		tableau[2] = 0;
		tableau[2] = 0;
	}
	return (tableau);
}

void		free_d(char **dtab, int lenght)
{
	int		i;

	i = 0;
	while (i < lenght)
	{
		free(dtab[i]);
		i++;
	}
	if (lenght != 0)
		free(dtab);
}

int			parser_data(t_llist *env, char **line, t_data **data, t_memory **me)
{
	while (*line)
	{
		if (ctrl_var(*line))
		{
			if (((*data)->cmd) == NULL)
				init_data(env, *line, data);
			else
			{
				(*data)->index += 1;
				if (option_ctrl(*data, *me, line) == QUOTE_OPT)
					line += (*me)->pos;
			}
			if (!(*data)->cmd)
				return (-1);
		}
		if (!ctrl_var(*line))
			return (define_variable(*me, *line));
		line++;
	}
	return (0);
}
