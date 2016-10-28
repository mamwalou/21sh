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

#include "../../includes/minishell.h"

int			dup_option(t_data *data, char **line, int pos, int nb_car)
{
	char	*new_opt;
	int		i;
	int		y;
	int		h;

	i = 0;
	h = 0;
	new_opt = (char*)ft_memalloc(nb_car + pos);
	while (i <= pos)
	{
		y = 0;
		while (line[i][y])
		{
			if (line[i][y] != 39 && line[i][y] != 34)
				new_opt[h++] = line[i][y];
			y++;
		}
		if (i != pos)
			new_opt[h++] = ' ';
		i++;
	}
	new_opt[h + 1] = 0;
	data->option = init_option(new_opt, data->option);
	data->index++;
	return (QUOTE_OPT);
}

int			open_quote_mode(void)
{
	return (SUCCESS);
}

int			option_ctrl(t_data *data, t_memory *memory, char **line)
{
	int		count;
	int		c_c;

	c_c = 0;
	memory->pos = 0;
	if (line[memory->pos][0] == 39 || line[memory->pos][0] == 34)
	{
		while (line[memory->pos])
		{
			count = 1;
			while (line[memory->pos][count])
			{
				if (line[memory->pos][count] == 39
					|| line[memory->pos][count] == 34)
					return (dup_option(data, line, memory->pos, c_c));
				c_c++;
				count++;
			}
			c_c++;
			memory->pos++;
		}
		return (open_quote_mode());
	}
	data->option = init_option(*line, data->option);
	return (SUCCESS);
}
