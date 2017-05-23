/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tc_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 01:38:43 by mbourget          #+#    #+#             */
/*   Updated: 2017/05/23 16:51:01 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

static int	tputc(int c)
{
	return (write(STDIN_FILENO, &c, 1));
}

void		tc_write(const char *cap, ...)
{
	char	*cap_cpy;
	int		c;
	int		coords[2];
	va_list	ap;

	cap_cpy = ft_strdup(cap);
	if (!ft_strchr(cap, '+'))
		tputs(tgetstr(cap_cpy, NULL), 1, tputc);
	else
	{
		c = 0;
		va_start(ap, cap);
		while (c < 2)
			coords[c++] = va_arg(ap, int);
		va_end(ap);
		tputs(tgoto(tgetstr(cap_cpy, NULL), coords[0], coords[1]), 1, tputc);
	}
	ft_strdel(&cap_cpy);
}
