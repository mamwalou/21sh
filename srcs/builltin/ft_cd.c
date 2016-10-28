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
#include "../../includes/minishell.h"

static int			ft_cdoneopt(t_data *data, t_llist *env, char *cpy)
{
	char			*buf;

	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	chdir(data->option[1]);
	unenv("PWD=", env);
	unenv("OLDPWD=", env);
	free(buf);
	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	export_var(&env, ft_strjoin("PWD=", buf));
	export_var(&env, ft_strjoin("OLDPWD=", cpy));
	free(buf);
	return (0);
}

static int			ft_cdone2opt(t_data *data, t_llist *env, char *cpy)
{
	char			*buf;

	buf = ft_memalloc(UCHAR_MAX);
	getcwd(buf, UCHAR_MAX);
	chdir("..");
	if ((is_dir(data->option[1]) == REP) && (is_dir(data->option[2]) == REP))
	{
		chdir(data->option[2]);
		ft_putendl(ft_strtrijoin(search_env(env, "HOME="), "/",
					data->option[2]));
		unenv("PWD=", env);
		unenv("OLDPWD=", env);
		free(buf);
		buf = ft_memalloc(UCHAR_MAX);
		getcwd(buf, UCHAR_MAX);
		export_var(&env, ft_strjoin("PWD=", buf));
		export_var(&env, ft_strjoin("OLDPWD=", cpy));
		free(buf);
		return (0);
	}
	chdir("buf");
	return (43);
}

static int			revers_cd(t_llist *env, char *newold)
{
	char			*cpy;

	cpy = ft_strdup(search_env(env, "OLDPWD="));
	chdir(cpy);
	unenv("PWD=", env);
	unenv("OLDPWD=", env);
	export_var(&env, ft_strjoin("PWD=", cpy));
	ft_putendl(ft_strjoin("~", ft_chrstr(search_env(env, "PWD="),
				search_env(env, "HOME="))));
	export_var(&env, ft_strjoin("OLDPWD=", newold));
	return (0);
}

int					ft_cd(t_data *data, t_llist *env, t_memory *memory)
{
	char			*cpy;
	int				i;

	cpy = ft_strdup(search_env(env, "PWD="));
	if (data->index == 1)
	{
		if (search_env(env, "HOME"))
		{
			chdir(search_env(env, "HOME="));
			unenv("PWD=", env);
			unenv("OLDPWD=", env);
			export_var(&env, ft_strjoin("PWD=", search_env(env, "HOME=")));
			export_var(&env, ft_strjoin("OLDPWD=", cpy));
		}
		return (1);
	}
	if (data->option[1][0] == '-')
		return (revers_cd(env, cpy));
	if (data->index > 3)
		return (48);
	if ((data->index == 2) && (is_dir(data->option[1]) == REP))
		return (ft_cdoneopt(data, env, cpy));
	else if (data->index == 3)
		return (ft_cdone2opt(data, env, cpy));
	return (66);
}
