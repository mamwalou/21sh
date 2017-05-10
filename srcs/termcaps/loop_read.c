#include "../../includes/termcaps/termcaps.h"
#include "../../includes/shell.h"

int			my_ctrl(int test)
{
	if (test == '-'
		|| test == ';'
		|| test == '<'
		|| test == '>'
		|| test == '&'
		|| test == '='
		|| test == '/'
		|| test == '.'
		|| test == '|'
		|| test == '"'
		|| test == '$'
		|| test == '~'
		|| test == '_'
		|| test == 92
		|| test == 96
		|| test == 39
		|| test == ' '
		|| test == '!')
		return (1);
}

static void 		loop(t_win *win, char buffer[MAX_LEN + 4], int i, uint64_t *y)
{
   unsigned char	*s;

   i = 0;
   *y = 0;
   if (buffer[0] != 10 && buffer[0] != 4)
   {
	   while (buffer[i])
	   {
		   push_line(win, (int)buffer[i]);
		   i++;
	   }
   }
   else
   {
	   i = 0;
	   s = (unsigned char*)buffer;
	   while (i < 8)
	   {
		   *y += (s[i] << (8 * i));
		   i++;
	   }
	   push_line(win, *y);
   }
}

void 			read_instance(t_win *win)
{
	uint64_t	y;
	int			z;

	z = 0;
	y = 0;
	ft_bzero(win->buffer, MAX_LEN + 1);
	while (y != 10 || (y == 10 && z != 0))
	{
		ft_bzero(win->buffer, MAX_LEN +1);
		read(0, win->buffer, MAX_LEN);
		if (input(win) > 0)
			;
		else if (win->buffer[0] != RETURN)
			loop(win, win->buffer, 0, &y);

		else
		{
			list_to_array(win);
			bring_back_shell(&(g_term.terminal));
			ft_putchar('\n');
			return ;
		}
		z = (win->lenght_line > 0) ? 1 : 0;
	}
	exit(1);
}
