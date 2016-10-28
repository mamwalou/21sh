/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int					is_dir(char *s)
{
	struct stat		buf;
	int				i;

	i = 0;
	if (stat(s, &buf) == -1)
		return (-1);
	i = S_ISREG(buf.st_mode) ? 50 : i;
	i = S_ISDIR(buf.st_mode) ? 60 : i;
	i = S_ISLNK(buf.st_mode) ? 70 : i;
	return (i);
}
