/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		l;
	char	*s2;

	l = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * l + 1)))
		return (NULL);
	if (s2 != NULL)
		ft_strcpy(s2, s1);
	else
		return (NULL);
	return (s2);
}
