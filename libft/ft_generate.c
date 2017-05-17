/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 04:30:45 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/17 04:30:46 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int			*generate(int c, int c1, int size)
{
	int		*tableau;

	tableau = (int*)ft_memalloc(sizeof(int) * size);
	if (size == 2)
	{
		tableau[0] = c;
		tableau[1] = 0;
	}
	if (size == 3)
	{
		tableau[0] = c;
		tableau[1] = c1;
		tableau[2] = 0;
	}
	return (tableau);
}
