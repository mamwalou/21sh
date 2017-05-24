/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lexer2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 00:37:35 by tcabon            #+#    #+#             */
/*   Updated: 2017/05/25 00:37:36 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer_parser.h"

int		ctrl_tab2(int count, char *line)
{
	count++;
	if (line[count] == '-')
		return (count + 1);
	while (ft_isdigit(line[count]))
		count++;
	return (count);
}
