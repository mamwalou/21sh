/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ast/ast.h"
#include "../../includes/shell.h"

t_token		define_token(char *lexem)
{
	if (!ft_strcmp(lexem, ">!&"))
		return (PIPE);
	if (!ft_strcmp(lexem, ">>&"))
		return (PIPE);
	if (!ft_strcmp(lexem, ">&"))
		return (PIPE);
	if (!ft_strcmp(lexem, "&&"))
		return (PIPE);
	if (!ft_strcmp(lexem, "||"))
		return (PIPE);
	if (!ft_strcmp(lexem, ">!"))
		return (PIPE);
	if (!ft_strcmp(lexem, ">>"))
		return (PIPE);
	if (!ft_strcmp(lexem, ">"))
		return (PIPE);
	if (!ft_strcmp(lexem, "|"))
		return (PIPE);
	if (!ft_strcmp(lexem, ";"))
		return (PIPE);
	return (CMD);
}
