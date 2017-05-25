/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_deep_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 06:43:56 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/25 03:01:31 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

bool	from_deep_space(char *str, size_t len)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str == ' ')
			++count;
		++str;
	}
	return (count == len ? true : false);
}
