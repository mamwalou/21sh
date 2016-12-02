/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/12/01 15:27:22 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int			can_var(t_memory *memory, char *line, t_data *data)
{
	char	**array;
	char	*cpy;
	int		len;

	generate(";", 1, data);
	len = parser(&array, memory->var, data->tableau);
	cpy = ft_strdup(memory->var);
	free(memory->var);
	memory->var = ft_strtrijoin(cpy, ";", line);
	free_d(array, len);
	free(cpy);
	return (7);
}

int			define_memory(t_memory *memory, char *line, t_data *data)
{
	if (memory->var)
		can_var(memory, line, data);
	else
		memory->var = ft_strdup(line);
	return (6);
}
