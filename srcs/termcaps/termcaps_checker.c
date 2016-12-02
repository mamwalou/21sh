/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/12/01 15:27:48 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

int				ft_puts(int c)
{
	write(1, &c, 1);
	return (0);
}

int				input(t_line **blst, t_line **end, t_memory *memory, t_win *win)
{
	if (*(unsigned int*)win->buffer == DELETE)
		return (depushline(blst, end, win));
	if (*(unsigned int*)win->buffer == DELETE)
		return (depushline(blst, end, win));
	if (*(unsigned int*)win->buffer == LEFT)
		return (gest_crs(*blst, *end, win));
	if (*(unsigned int*)win->buffer == RIGHT)
		return (gest_crs(*blst, *end, win));
	return(0);
}
