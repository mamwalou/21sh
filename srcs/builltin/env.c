/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:23:36 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 06:18:10 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			print_env(void)
{
	t_llist		*ptr;

	ptr = g_env;
	while (ptr)
	{
		ft_putendl(ptr->content);
		ptr = ptr->next;
	}
}
