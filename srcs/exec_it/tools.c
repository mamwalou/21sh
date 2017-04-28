/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/25 16:49:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/shell.h"

int						reset_fd(int fd, char *new_fd)
{
	int					new;

	close(fd);
	new = open(new_fd, O_RDWR | O_CREAT | O_APPEND, 0666);
	return (new);
}

char					*get_pwd(void)
{
	char		*pwd;
	char		buff[BUFF_SIZE];

	pwd = getcwd(buff, BUFF_SIZE);
	return (pwd);
}

char					**copy_env(void)
{
	t_llist				*ptr;
	char				**cpy;
	int					count;

	if (g_env != NULL)
	{
		count = 0;
		ptr = g_env;
		cpy = (char**)malloc(sizeof(char*) * g_env->maillon_nb + 1);
		while (count < g_env->maillon_nb)
		{
			cpy[count] = ft_strdup(ptr->content);
			count++;
			ptr = ptr->next;
		}
		cpy[count] = NULL;
		return (cpy);
	}
	return (NULL);
}

void					*ft_realloc(void *mem, size_t size)
{
	char				*buff;

	if (mem == NULL)
		return (malloc(size));
	if (size <= 0)
		return (NULL);
	buff = (void*)malloc(size);
	if (buff)
		ft_memcpy(buff, mem, size);
	free(mem);
	return (buff);
}

void					free_d(char **dtab)
{
	while (*dtab)
	{
		free(*dtab);
		dtab++;
	}
}
