#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

void		list_to_array(t_win *win)
{
	t_line	*ptr;
	char	*save;
	int		i;

	i = 0;
	save = NULL;
	if (win->begin != NULL)
	{
		if (g_memory.line != NULL)
		{
			save = ft_strdup(g_memory.line);
			free(g_memory.line);
		}
		g_memory.line = (char*)ft_memalloc(sizeof(char) * win->lenght_line);
		g_memory.line_lenght = win->lenght_line;
		ptr = win->begin;
		while (ptr)
		{
			g_memory.line[i] = ptr->l_char;
			ptr = ptr->next;
			free(win->begin);
			win->begin = ptr;
			i++;
		}
		g_memory.line[i] = '\0';
	}
	if (save)
		g_memory.line = ft_strjoin(save, g_memory.line);
}

void			list_lchar(char *str, t_win *win)
{
	while (*str != ';')
		str++;
	str++;
	while (*str)
	{
		push_line(win, *str);
		str++;
	}
}

char			*lchar_list(t_line *line, int lenght)
{
	char	*str;
	t_line	*ptr;
	int		i;

	i = 0;
	ptr = line;
	str = (char*)ft_memalloc(sizeof(char) * lenght + 1);
	while (ptr)
	{
		str[i] = ptr->l_char;
		ptr = ptr->next;
		i++;
	}
	str[lenght + 1] = 0;
	return (str);
}
