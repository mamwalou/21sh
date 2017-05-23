/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbourget <mbourget@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 11:21:00 by sbeline           #+#    #+#             */
/*   Updated: 2017/05/23 17:20:39 by mbourget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcaps.h"

void			handl_sigws(int sig)
{
	char		cp[2];

	cp[0] = 0;
	cp[1] = 0;
	ioctl(0, TIOCGWINSZ, &(g_term.apt));
	ioctl(0, TIOCSTI, cp);
}

void			handl_sigstrp(int sig)
{
	char		cp[2];

	cp[0] = g_term.terminal.c_cc[VSUSP];
	cp[1] = 0;
	tputs(tgetstr("cl", NULL), 1, ft_puts);
	bring_back_shell(&(g_term.terminal));
	signal(SIGTSTP, SIG_DFL);
	ioctl(0, TIOCSTI, cp);
}

void			handl_sigcont(int sig)
{
	char		cp[2];

	cp[0] = '.';
	cp[1] = 0;
	// if (init_term(&(g_term.terminal)) == -1)
	// 	return ;
	g_term.lock = 1;
	signal(SIGTSTP, handl_sigstrp);
	ioctl(0, TIOCSTI, prompt());
}

void			handl_sig(void)
{
	signal(SIGKILL, SIG_IGN);
	signal(SIGSEGV, SIG_IGN);
	signal(SIGTSTP, handl_sigstrp);
	signal(SIGCONT, handl_sigcont);
}
