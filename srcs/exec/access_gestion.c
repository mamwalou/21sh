#include "../../includes/exec/exec.h"

int  			print_error(char *cmd, t_code code)
{
	if (code = CD_CMD)
		ft_putstr_fd("shell: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	return (-1);
}

char			*ctrl_access(char **path, char *name)
{
	char		*tmp;
	int			count;

	count = 0;
	tmp = NULL;
	while (path[count])
	{
		tmp = ft_strtrijoin(path[count], "/", name);
		if (access(tmp, X_OK) == 0)
			return (tmp);
		count++;
	}
	free(tmp);
	return (NULL);
}

char			**find_path(void)
{
	char		**path;
	int			*tableau;
	int			lenght;

	lenght = 0;
	path = NULL;
	tableau = generate(':', 0 , 3);
	lenght = ft_strsplit(&path, search_env(g_env, "PATH="), tableau);
	free(tableau);
	if (!lenght)
		return (NULL);
	return (path);
}

int				find_command(char **cmd)
{
	char		**path;
	char		*tmp;

	tmp = NULL;
	if (is_bulltin(*cmd))
		return (0);
	else if (access(*cmd, X_OK) == 0)
		return (0);
	if ((path = find_path()) == NULL)
		return (print_error(*cmd, CD_CMD));
	if ((tmp = ctrl_access(path, *cmd)) == NULL)
	{
		free(path);
		free(tmp);
		return (print_error(*cmd, CD_CMD));
	}
	else
	{
		free(path);
		MACREALLOC(*cmd, tmp, ft_strlen(tmp) + 1);
	}
	return (1);
}
