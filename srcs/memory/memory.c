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

int			can_var(t_memory *memory, char *line, t_data *data)
{
	char	**array;
	char	*cpy;
	int		i;
	int		len;

	i = 0;
	generate(';', 0, 2, data);
	len = ft_strsplit(&array, memory->var, data->tableau);
	cpy = ft_strdup(memory->var);
	free(memory->var);
	memory->var = ft_strtrijoin(cpy, ";", line);
	free_d(array, len);
	free(cpy);
	return (7);
}

int			define_memory(t_memory *memory, char *line, t_data *data)
{
	char			*cpy;

	if (memory->var)
		can_var(memory, line, data);
	else
		memory->var = ft_strdup(line);
	return (6);
}
