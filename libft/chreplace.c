/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chreplace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 03:25:40 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/25 01:31:30 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	chreplace(char *s, char to_find, char new)
{
	while (*s)
	{
		if (*s == to_find)
			*s = new;
		++s;
	}
}
