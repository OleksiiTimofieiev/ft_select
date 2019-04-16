/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:52:44 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/16 19:53:04 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		ctrl_z_handler(void)
{
	restore_terminal(&g_evil);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
}

static void		signals_routines(int type_of_signal)
{
	if (type_of_signal == SIGWINCH)
	{
		init_coordinates(&g_evil.head, g_evil.longest);
		print_to_terminal(g_evil.input);
		init_up_down(&g_evil);
	}
	else if (type_of_signal == SIGTSTP)
		ctrl_z_handler();
	else if (type_of_signal == SIGCONT)
	{
		init_terminal(g_evil.termtype);
		init_signals();
		init_terminal_state(&g_evil, g_evil.input, g_evil.longest);
		print_to_terminal(g_evil.input);
		init_up_down(&g_evil);
		main_loop();
	}
	else
	{
		restore_terminal(&g_evil);
		exit(-1);
	}
}

void			init_signals(void)
{
	signal(SIGSTOP, signals_routines);
	signal(SIGCONT, signals_routines);
	signal(SIGWINCH, signals_routines);
	signal(SIGINT, signals_routines);
	signal(SIGABRT, signals_routines);
	signal(SIGKILL, signals_routines);
	signal(SIGQUIT, signals_routines);
	signal(SIGTERM, signals_routines);
}
