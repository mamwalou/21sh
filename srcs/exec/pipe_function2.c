/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 10:58:06 by sbeline           #+#    #+#             */
/*   Updated: 2017/04/20 19:39:30 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void					new_pid(t_pipe *pipe, pid_t pid)
{
	if (pid < 0)
		return ;
	if (pipe->list == NULL)
	{
		pipe->list = (pid_t*)malloc(sizeof(char*) * 2);
		pipe->list[0] = pid;
		pipe->list[1] = 0;
		pipe->count++;
	}
	else
	{
		MACREALLOC(pipe->list, pipe->list, ++pipe->count + 1 * sizeof(pid_t));
		pipe->list[pipe->count - 1] = pid;
		pipe->list[pipe->count] = pid;

	}
}

pid_t					verif_pid(t_pipe *pipe)
{
	if (pipe->count <= 0 || pipe->last + 1 >= pipe->count)
		return (-1);
	return (pipe->list[++pipe->last]);
}
