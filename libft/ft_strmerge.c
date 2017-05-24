/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/07 13:12:55 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 02:20:49 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strmerge(char *s1, char *s2, int free_s1, int free_s2)
{
	char	*merged;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	merged = (char *)ft_memalloc(sizeof(char) * (s1_len + s2_len + 1));
	if (merged == NULL)
		return (NULL);
	ft_memcpy(merged, s1, s1_len);
	ft_memcpy(merged + s1_len, s2, s2_len);
	if (free_s1)
		ft_strdel(&s1);
	if (free_s2)
		ft_strdel(&s2);
	return (merged);
}
