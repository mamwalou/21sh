/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_histfile_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/24 11:53:11 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void	get_histfile_path(void)
{
	char	*tmp;
	char	*tmp2;

	if (search_env(g_env, "HOME="))
	{
		tmp = ft_strtrijoin("HISTORY=", search_env(g_env, "HOME="), "/");
		tmp2 = ft_strjoin(tmp, ".my_history");
		ft_lstadd(&g_env, ft_lstnew(tmp2, ft_strlen(tmp2)));
		g_memory.env_lenght++;
		free(tmp);
		free(tmp2);
	}
}
