/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:16:52 by salomon           #+#    #+#             */
/*   Updated: 2016/12/05 16:26:06 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int		cmp(int to_cmp, char *cmp)
{
	while (*cmp)
	{
		if (*cmp == to_cmp)
			return (0);
		cmp++;
	}
	return (1);
}

int				ft_strint(char *str, char *str_cmp)
{
	int		i;

	i = 0;

	while (str[i] && (cmp(str[i], str_cmp)) == 0)
		i++;
	if (i == 0)
		return (1);
	return (i);
}
