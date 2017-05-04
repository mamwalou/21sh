/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void			*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	i = 0;
	dest2 = s1;
	src2 = s2;
	while (n > i)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest2);
}
