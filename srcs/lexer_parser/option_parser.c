/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

static char			**push_option(char *opt, char **save, int index)
{
	int				pos;
	char			**nw_opt;
	int				count;

	pos = 0;
	count = 0;
	while (save[pos])
		pos++;
	pos += 1;
	nw_opt = (char**)malloc(sizeof(char*) * pos + 1);
	while (save[count])
	{
		nw_opt[count] = ft_strdup(save[count]);
		count++;
	}
	nw_opt[count] = ft_strdup(opt);
	nw_opt[count + 1] = 0;

	free_d(save, index);
	return (nw_opt);
}

char				**init_option(char *opt, char **save, int index)
{
	char			**nw_opt;
	int				pos;

	if (save == NULL)
	{
		nw_opt = (char**)malloc(sizeof(char*) + 1);
		nw_opt[0] = ft_strdup(opt);
		nw_opt[1] = 0;
		return (nw_opt);
	}
	else
		return (push_option(opt, save, index));
	return (nw_opt);
}

/*int			option_ctrl(t_data *data, t_memory *memory, char **line)
{

	data->option = init_option(*line, data->option, data->index);
	return (SUCCESS);
}*/
