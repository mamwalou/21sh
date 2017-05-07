/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/07 21:23:54 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lexer_parser/lexer_parser.h"

static char			**push_option(char *opt, char **save, int index)
{
	char			**re_opt;
	int				count;

	count = 0;
	re_opt = (char**)malloc(sizeof(char*) * (index + 2));
	while (save[count] != NULL)
	{
		re_opt[count] = ft_strdup(save[count]);
		free(save[count]);
		printf("re_opt[count](%p),save[count](%p)\n",re_opt[count], save[count]);
		count++;
	}
	re_opt[count] = ft_strdup(opt);
	count++;
	re_opt[count] = NULL;
	free(save);
	return (re_opt);
}

char				**init_option(char *opt, char **save, int index)
{
	char			**nw_opt;

	nw_opt = NULL;
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
