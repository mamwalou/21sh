/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

t_llist		*ft_lstnew(void const *content, size_t content_size)
{
	t_llist	*ptr;
	void	*cnt;

	cnt = (void*)ft_memalloc(content_size + 1);
	cnt = ft_memcpy(cnt, content, content_size);
	ptr = (t_llist*)ft_memalloc(sizeof(t_llist));
	ptr->content_size = content_size;
	ptr->content = cnt;
	ptr->maillon_nb = 0;
	ptr->next = NULL;
	return (ptr);
}
