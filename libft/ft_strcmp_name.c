/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int		ft_strcmp_name(char *s1, char *s2)
{
	char	c1;
	char	c2;

	while (*s1 == *s2)
	{
		s2++;
		s1++;
	}
	c1 = *s1 >= 'A' && *s1 <= 'Z' ? *s1 + 32 : *s1;
	c2 = *s2 >= 'A' && *s2 <= 'Z' ? *s2 + 32 : *s2;
	if (c2 < c1)
		return (1);
	return (-1);
}
