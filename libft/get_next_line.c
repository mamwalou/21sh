/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdriay <mdriay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/23 21:50:21 by mdriay            #+#    #+#             */
/*   Updated: 2017/05/02 13:16:45 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static int		get_concat(char **line, char *buf, int n)
{
	char	*ret;
	int		len;

	len = (*line ? ft_strlen(*line) : 0);
	if (!(ret = (char*)malloc(sizeof(ret) * (len + n + 1))))
		return (0);
	ft_bzero(ret, len + n + 1);
	if (*line)
	{
		ft_strcpy(ret, *line);
		free(*line);
	}
	ft_strncat(ret, buf, n);
	*line = ret;
	return (1);
}

static int		get_refresh(char *buf, int i)
{
	ft_strncpy(buf, &(buf[i]), BUFF_SIZE);
	return (1);
}

static int		get_loop(int const fd, int *check, char **buf, char **line)
{
	int i;

	i = 0;
	while ((*buf)[i] != '\n' && !((*buf)[i] == '\0' && *check == 0))
	{
		if ((*buf)[i] == '\0')
		{
			if (!get_concat(line, *buf, i))
				return (-1);
			*check = read(fd, (*buf), BUFF_SIZE);
			(*buf)[*check] = 0;
			i = -1;
		}
		i++;
	}
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	static char *buf;
	static int	check;
	int			i;

	if (fd < 0 || fd >= 99 || (fd == 1 && line == NULL))
		return (-1);
	*line = NULL;
	if (!check)
	{
		if (!(buf = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
		check = read(fd, buf, BUFF_SIZE);
		buf[check] = 0;
	}
	if (check == 0)
		return (0);
	i = get_loop(fd, &check, &buf, line);
	if (buf[i] == '\n' || buf[i] == '\0')
	{
		if (!get_concat(line, buf, i) || !get_refresh(buf, i + 1))
			return (-1);
	}
	if (check == 0 && buf[0] != '\0')
		return (1);
	return (check ? 1 : 0);
}
