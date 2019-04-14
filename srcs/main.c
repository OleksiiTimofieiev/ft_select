/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 23:41:08 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// TODO: norminette in all directories;
// TODO: check static ones to local funcs;

// TODO: arrows to the next // previous column;

/* 3 */
// TODO: # define NO_ROOM "Not enough space! Resize window."
// TODO: not possible to show everithing; if size is ok -> show everithing;

int		print_key(int n)
{
	return (write(INPUT_FD, &n, 1));
}

 void	ctrl_z_handler(void)
{
	restore_terminal(&g_evil);
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDIN_FILENO, TIOCSTI, "\x1A");
}

void	signals_routines(int type_of_signal)
{
	if (type_of_signal == SIGWINCH)
	{
		init_coordinates(&g_evil.head, g_evil.longest);
		print_to_terminal(g_evil.input);
		// initial_select(&g_evil, g_evil.longest);
	}
	else if (type_of_signal == SIGTSTP)
		ctrl_z_handler();
	else if (type_of_signal == SIGCONT)
	{
		init_terminal(g_evil.termtype);
		init_signals();
		// init_coordinates(&input, len);
		// init_color(input);
		init_terminal_state(&g_evil, g_evil.input, g_evil.longest);
		// init_signals();
		print_to_terminal(g_evil.input);
		main_loop();

	}
	else
	{
		restore_terminal(&g_evil);
		exit(-1);
	}
}

void	init_signals(void)
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


// void sl_init_term(void)
// {
// 	int32_t res;

// 	if (!isatty(STDIN_FILENO))
// 		sl_init_fatal_err_exit(NOT_A_TERM);
// 	if (!(sl()->termtype = getenv("TERM")))
// 		sl_init_fatal_err_exit(MSG(NO_TERM, NULL));
// 	if ((res = tgetent(NULL, sl()->termtype)) == ERR)
// 		sl_init_fatal_err_exit(NO_ACCESS_TO_DB);
// 	else if (res == 0)
// 		sl_init_fatal_err_exit(MSG(NO_SUCH_ENTRY, sl()->termtype));
// 	sl_set_new_attr();
// 	tputs(tgetstr("ti", NULL), 1, sl_print_key);
// 	tputs(tgetstr("vi", NULL), 1, sl_print_key);
// }

// void sl_sig_hendler(int sig)
// {
// 	// else if (sig == SIGTSTP)
// 	// 	sl_ctrl_z();
// 	else if (sig == SIGCONT)
// 	{
// 		// sl_init_term();
// 		// sl_init_signals();
// 		// if (sl()->music)
// 		// 	sl_music_on();
// 		// sl_print_all();
// 	}
// 	else
// 		exit(-1);
// }





int		main(int argc, char **argv)
{
	int				len;
	t_input 		*input;

	init_terminal(g_evil.termtype);
	init_data(--argc, argv, &input, &len);
	init_coordinates(&input, len);
	init_color(input);
	init_terminal_state(&g_evil, input, len);
	init_signals();
	print_to_terminal(input);
	// initial_select(&g_evil, len);
	main_loop();
	return (0);
}

// bonus: colors, dynamic search;