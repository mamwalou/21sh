/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

static t_fd		*new_data_fd(int const fd)
{
	t_fd	*new;

	if ((new = (t_fd *)malloc(sizeof(t_fd))) != NULL)
	{
		new->fd = fd;
		new->nl = 0;
		new->pos_nl = 0;
		new->ret = 0;
		new->buf = NULL;
		new->next = NULL;
	}
	return (new);
}

static t_fd		*get_data_fd(t_fd **lst_fd, int const fd)
{
	t_fd	*tmp;

	if (*lst_fd == NULL)
		return ((*lst_fd = new_data_fd(fd)));
	tmp = *lst_fd;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		else if (tmp->next == NULL)
			return ((tmp->next = new_data_fd(fd)));
		tmp = tmp->next;
	}
	return (NULL);
}

static void		ft_read(t_fd *d_fd)
{
	char		*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
	if ((d_fd->ret = read(d_fd->fd, tmp, BUF_SIZE)) == -1)
		return ;
	tmp[d_fd->ret] = '\0';
	d_fd->buf = ft_stradd(&d_fd->buf, &tmp);
	while ((d_fd->pos_nl = ft_strchr(d_fd->buf, '\n')) == 0 && d_fd->ret > 0)
	{
		tmp = (char *)malloc(sizeof(char) * (BUF_SIZE + 1));
		if ((d_fd->ret = read(d_fd->fd, tmp, BUF_SIZE)) == -1)
			return ;
		tmp[d_fd->ret] = '\0';
		d_fd->buf = ft_stradd(&d_fd->buf, &tmp);
	}
	if (d_fd->ret > 0)
		d_fd->ret = 1;
}

int				get_next_line(int const fd, char **line)
{
	static t_fd		*lst_fd = NULL;
	t_fd			*d_fd;

	if (fd < 0 || line == NULL || (d_fd = get_data_fd(&lst_fd, fd)) == NULL)
		return (-1);
	if (d_fd->buf == NULL)
		d_fd->buf = ft_strnew(BUF_SIZE + 1, "");
	if ((d_fd->pos_nl = ft_strchr(d_fd->buf, '\n')) == 0)
		ft_read(d_fd);
	if (d_fd->ret == 0 && d_fd->pos_nl == 0)
		d_fd->pos_nl = ft_strlen(d_fd->buf) + 1;
	if (d_fd->ret != -1 && d_fd->pos_nl != 0)
	{
		*line = ft_strsub(d_fd->buf, 0, d_fd->pos_nl - 1);
		ft_strmove(&(d_fd->buf), d_fd->pos_nl);
		d_fd->pos_nl = 0;
		if (*d_fd->buf == '\0' && d_fd->ret == 0)
			ft_strdel(&(d_fd->buf));
	}
	return (d_fd->ret);
}
