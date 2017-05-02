#include "../../includes/shell.h"

char			**convert_history(char *path_memory, int lenght)
{
	char		**str;
	char		*buf;
	int			fd;
	int			i;

	i = 0;
	buf = NULL;
	fd = open(path_memory, O_RDWR | O_CREAT | O_APPEND, 0666);
	str = (char**)malloc(sizeof(char*) * lenght);
	while ((get_next_line(fd, &buf)) > 0)
	{
		str[i] = ft_strdup(buf);
		i++;
	}
	ft_putnbr(lenght);
	ft_putchar('\n');
	free(buf);
	close(fd);
	return (str);
}
