/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char *tmp;
	char *tmp1;

	tmp1 = s1;
	tmp = (char*)s2;
	while (*tmp1 != '\0')
		tmp1++;
	while (*tmp != '\0')
	{
		*tmp1 = *tmp;
		tmp++;
		tmp1++;
	}
	*tmp1 = '\0';
	return (s1);
}
