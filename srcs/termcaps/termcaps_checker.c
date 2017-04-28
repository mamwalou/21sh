/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/23 20:24:09 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

int			ft_puts(int c)
{
	write(1, &c, 1);
	return (0);
}

int			input(t_win *win)
{
	if (*(unsigned int*)win->buffer == DELETE)
	{
		if (win->end != NULL)
			depushline(win);
		return (0);
	}
	if (*(unsigned int*)win->buffer == LEFT)
		return (gest_crs(win));
	if (*(unsigned int*)win->buffer == RIGHT)
		return (gest_crs(win));
	return (0);
}
