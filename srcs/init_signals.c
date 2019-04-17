/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:52:44 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 15:05:58 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void init_terminal_state_2(t_global *g_evil, int len)
{
	tcgetattr(INPUT_FD, &g_evil->initial_terminal_state);
	tcgetattr(INPUT_FD, &g_evil->new_terminal_state);
	g_evil->new_terminal_state.c_lflag &= ~(ICANON | ECHO);
	g_evil->new_terminal_state.c_cc[VMIN] = 1;
	g_evil->new_terminal_state.c_cc[VTIME] = 0;
	tcsetattr(INPUT_FD, TCSANOW, &g_evil->new_terminal_state);
	init_termcap(&g_evil->terminal_state);
	tputs(tgetstr("ti", NULL), 1, print_key);
	tputs(tgetstr("vi", NULL), 1, print_key);
	g_evil->longest = len;
}

void ctrl_z_handler(void)
{
	restore_terminal(&g_evil);
	signal(SIGTSTP, SIG_DFL);
	ioctl(OUTPUT_FD, TIOCSTI, "\x1A");
	// ft_putstr_fd("5\n", 0);
}

static void		signals_routines(int type_of_signal)
{
	if (type_of_signal == SIGTSTP)
	{
		ft_putstr_fd("1\n", 0);
		ctrl_z_handler();
	}
	else if(type_of_signal == SIGWINCH)
	{
		ft_putstr_fd("2\n", 0);

		init_coordinates(&g_evil.head, g_evil.longest);
		print_to_terminal(g_evil.input);
		init_up_down(&g_evil);
	}
	else if (type_of_signal == SIGCONT)
	{
		ft_putstr_fd("3\n", 0);
		// ft_putstr_fd("asdfasdfasdfasdfasdf", 0);

		init_terminal(g_evil.termtype);
		init_signals();
		init_terminal_state_2(&g_evil, g_evil.longest);
		init_up_down(&g_evil);
		print_to_terminal(g_evil.input);
		// main_loop();
	}
	else
	{
		ft_putstr_fd("4\n", 0);

		restore_terminal(&g_evil);
		exit(-1);
	}
}

void			init_signals(void)
{
	signal(SIGTSTP, signals_routines);
	signal(SIGSTOP, signals_routines);
	signal(SIGCONT, signals_routines);
	signal(SIGWINCH, signals_routines);
	signal(SIGINT, signals_routines);
	signal(SIGABRT, signals_routines);
	signal(SIGKILL, signals_routines);
	signal(SIGQUIT, signals_routines);
	signal(SIGTERM, signals_routines);
}
