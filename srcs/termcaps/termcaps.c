/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/23 17:33:44 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"
#include "shell.h"

// void			bring_back_shell(struct termios *term)
// {
// 	if (tcsetattr(0, 0, term) == -1)
// 		return ;
// }

void	sh_abort(char *msg)
{
	ft_putstr_fd("21sh: ", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	init_term(t_memory *sh)
{
	struct ttysize	ts;

	if (!isatty(STDIN_FILENO))
		sh_abort("not a tty");
	if (strncmp(ttyname(STDIN_FILENO), "/dev/", 5))
		sh_abort("invalid tty name");
	if (tgetent(NULL, getenv("TERM")) < 0)
		sh_abort("loading terminal entry failed");
	if (tcgetattr(STDIN_FILENO, &(sh->term)) < 0)
		sh_abort("cannot get terminal attributes");
	sh->term_d = sh->term;
	tc_unset_canonical(sh);
	sh->inp.maxlen = 1024;
	sh->inp.cbuf = (char *)ft_memalloc(sh->inp.maxlen);
	sh->inp.cmd = &(sh->inp.cbuf[PROMPT_SIZE]);
	sh->inp.cbuflen = PROMPT_SIZE;
	ft_strcpy(sh->inp.cbuf, PROMPT);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &ts);
	sh->curs.win_x = ts.ts_cols;
	sh->curs.x_max = ts.ts_cols - 1;
	sh->curs.x = PROMPT_SIZE;
	sh->curs.i = PROMPT_SIZE;
}

void			termcaps(t_memory *sh)
{
	int		ret;

	while ((ret = read(STDIN_FILENO, sh->inp.rbuf, RBUF_SIZE)) >= 0)
	{
		evt_handler(sh);
		ft_bzero(sh->inp.rbuf, sizeof(sh->inp.rbuf));
		if (sh->inp.ready)
		{
			sh->line = sh->inp.cmd;
			sh->line_lenght = sh->inp.cmdlen;
			sh->inp.ready = false;
			break ;
		}
	}
}
