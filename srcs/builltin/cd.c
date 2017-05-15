/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 10:27:23 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/15 20:31:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/exec/exec.h"

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
		replace_env(&g_env, "PWD=", home, &g_memory.env_lenght);
		replace_env(&g_env, "OLDPWD=", pwd, &g_memory.env_lenght);
	}
	free(pwd);
}

void			dash_one(char *str)
{
	char		*tmp;
	char		*save_pwd;
	char		*pwd;

	save_pwd = get_pwd();
	chdir(str);
	if (!search_env(g_env, "PWD="))
	{
		pwd = ft_strjoin("PWD=", get_pwd());
		ft_lstadd(&g_env, ft_lstnew(pwd, ft_strlen(pwd)));
		free(pwd);
	}
	if (!search_env(g_env, "OLDPWD="))
		ft_lstadd(&g_env, ft_lstnew(save_pwd, ft_strlen(save_pwd)));
	else if (search_env(g_env, "OLDPWD=") && search_env(g_env, "PWD="))
	{
		replace_env(&g_env, "OLDPWD=", save_pwd, &g_memory.env_lenght);
		tmp = get_pwd();
		replace_env(&g_env, "PWD=", tmp, &g_memory.env_lenght);
		free(tmp);
	}
	free(save_pwd);
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
