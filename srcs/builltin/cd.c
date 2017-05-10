/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:27:23 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/07 08:57:37 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

void			replace_env(char *sigle, char *new)
{
	char		*to_env;

	clear_env(&g_env, sigle);
	to_env = ft_strjoin(sigle, new);
	ft_lstadd(&g_env, ft_lstnew(to_env, ft_strlen(to_env)));
	free(to_env);
}

void			go_home(void)
{
	char		*home;
	char		*pwd;

	pwd = get_pwd();
	if ((home = search_env(g_env, "HOME=")) == NULL)
		ft_putendl_fd("no home set", 2);
	else
	{
		chdir(home);
		replace_env("PWD=", home);
		replace_env("OLDPWD=", pwd);
	}
}

void			dash_one(char *str)
{
	char		*tmp;
	char		buff[BUFF_SIZE];
	char		*save_pwd;
	char		*pwd;

	save_pwd = get_pwd();
	chdir(str);
	if (!search_env(g_env, "PWD="))
	{
		pwd = ft_strjoin("PWD=", get_pwd());
		ft_lstadd(&g_env, ft_lstnew(pwd, ft_strlen(pwd)));
	}
	if (!search_env(g_env, "OLDPWD="))
		ft_lstadd(&g_env, ft_lstnew(save_pwd, ft_strlen(save_pwd)));
	else if (search_env(g_env, "OLDPWD=") && search_env(g_env, "PWD="))
	{
		replace_env("OLDPWD=", save_pwd);
		replace_env("PWD=", get_pwd());
	}
}

void			ft_cd(char **cmd, int index)
{
	if (index == 4)
		ft_putendl_fd("cd: too many arguments", 2);
	if (index == 1)
		go_home();
	if (index > 1)
	{
		if (*cmd[1] == '~')
			go_home();
		else if (*cmd[1] == '-' && search_env(g_env, "OLDPWD="))
			dash_one(search_env(g_env, "OLDPWD="));
		else if (index == 2 && is_dir(cmd[1]) == REP)
			dash_one(cmd[1]);
		else
		{
			ft_putstr_fd("cd: no such file or directory:", 2);
			ft_putendl_fd(cmd[1], 2);
		}
	}
}
