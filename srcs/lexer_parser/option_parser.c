/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/02 12:39:19 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

static char			**push_option(char *opt, char **save, int index)
{
	char			**nw_opt;
	int				count;

	count = 0;
	nw_opt = (char**)malloc(sizeof(char*) * (index + 1));
	while (count < index)
	{
		nw_opt[count] = ft_strdup(save[count]);
		free(save[count]);
		count++;
	}
	nw_opt[count] = ft_strdup(opt);
	nw_opt[count + 1] = NULL;
	free(save);
	return (nw_opt);
}

char				**init_option(char *opt, char **save, int index)
{
	char			**nw_opt;
	int				pos;

	if (index == 0)
	{
		nw_opt = (char**)malloc(sizeof(char*) * 2);
		nw_opt[0] = ft_strdup(opt);
		nw_opt[1] = NULL;
		return (nw_opt);
	}
	else
		return (push_option(opt, save, index));
	return (NULL);
}
