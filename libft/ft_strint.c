/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 04:31:01 by sbeline          ###   ########.fr       */
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
		return (0);
	return (i);
}
