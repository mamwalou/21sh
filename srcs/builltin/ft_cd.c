/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int			ft_cdone2opt(t_data *data, t_llist *env, char *cpy)
{
	char			*buf;
	char			*pwd;
	char			*old_pwd;

	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	chdir("..");
	if ((is_dir(data->option[1]) == REP) && (is_dir(data->option[2]) == REP))
	{
		chdir(data->option[2]);
		ft_realloc(buf, UCHAR_MAX, UCHAR_MAX);
		getcwd(buf, UCHAR_MAX);
		pwd = ft_strjoin("PWD=", buf);
		old_pwd = ft_strjoin("OLDPWD=", cpy);
		export_var(&env, pwd, data);
		export_var(&env, old_pwd, data);
		free(buf);
		free(old_pwd);
		free(cpy);
		free(pwd);
		return (0);
	}
	chdir(buf);
	free(buf);
	return (43);
}

static int			revers_cd(t_llist *env, char *newold, t_data *data)
{
	char			*cpy;
	char			*tmp_pwd;
	char			*old_pwd;
	char			*aff;

	cpy = ft_strdup(search_env(env, "OLDPWD="));
	chdir(cpy);
	tmp_pwd = ft_strjoin("PWD=", cpy);
	export_var(&env, tmp_pwd, data);
	aff = ft_strjoin("~", cpy);
	ft_putendl(aff);
	old_pwd = ft_strjoin("OLDPWD=", newold);
	export_var(&env, old_pwd, data);
	free(cpy);
	free(aff);
	free(tmp_pwd);
	free(old_pwd);
	free(newold);
	return (0);
}

static int			cd_only(t_data *data, t_llist *env, char *cpy)
{
	char			*pwd;
	char			*old_pwd;

	pwd = ft_strjoin("PWD=", search_env(env, "HOME="));
	old_pwd = ft_strjoin("OLDPWD=", cpy);
	chdir(search_env(env, "HOME="));
	export_var(&env, pwd, data);
	export_var(&env, old_pwd, data);
	free(pwd);
	free(old_pwd);
	free(cpy);
	return (0);
}

static int			ft_cdoneopt(t_data *data, t_llist *env, char *cpy)
{
	char			*buf;
	char			*pwd;
	char			*old_pwd;

	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	chdir(data->option[1]);
	getcwd(buf, UCHAR_MAX);
	pwd = ft_strjoin("PWD=", buf);
	old_pwd = ft_strjoin("OLDPWD=", cpy);
	export_var(&env, pwd, data);
	export_var(&env, old_pwd, data);
	free(buf);
	free(cpy);
	free(old_pwd);
	free(pwd);
	return (0);
}

int					ft_cd(t_data *data, t_llist *env, t_memory *memory)
{
	char			*cpy;
	int				i;

	if (env != NULL)
	{
		cpy = ft_strdup(search_env(env, "PWD="));
		if (data->index == 1)
			return (cd_only(data, env, cpy));
		if (data->option[1][0] == '-')
			return (revers_cd(env, cpy, data));
		if (data->index > 2)
			return (48);
		if ((data->index == 2) && (is_dir(data->option[1]) == REP))
			return (ft_cdoneopt(data, env, cpy));
		else if (data->index == 3)
			return (ft_cdone2opt(data, env, cpy));
		return (66);
			}
	return (ER_NOENVSET);
}
