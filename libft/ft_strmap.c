/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_res;
	int		i;

	if (!s || !f)
		return (NULL);
	if ((str_res = ft_strdup((char*)s)) == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_res[i] = f(s[i]);
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}
