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
// TODO: check static ones;

// TODO: arrows to the next // previous column;

/* 3 */
// TODO: large vs small window; set_coordinates(*input = g_head, g_word_per_line = tgetnum("co") / (g->longest + SPACES), longets);
// TODO: The cursor of selection must be repositioned in a reasonable manner after a resizing.
// TODO: # define NO_ROOM "Not enough space! Resize window."
// TODO: not possible to show everithing; if size is ok -> show everithing;
// TODO: check how the change size signal works; on every move = +;
// TODO: Whichever way your program ends, the default configuration of your terminal MUST be restored. This is true even after it received a signal (except for the signals that we cannot intercept, but this would mean that your program does not work).
// TODO: We must be able to interrupt your program with ctrl+z and restore it with fg without seeing any changes in its behavior.
// TODO: correction form;

// void sl_set_base_settings(void)
// {
// 	tcsetattr(STDIN_FILENO, TCSANOW, &sl()->base_attr);
// 	tputs(tgetstr("ve", NULL), 1, sl_print_key);
// 	tputs(tgetstr("te", NULL), 1, sl_print_key);
// 	if (sl()->music)
// 		sl_music_off();
// }

// void sl_init_signals(void)
// {
// 	if (sl()->print_intro)
// 		signal(SIGWINCH, SIG_DFL);
// 	else
// 		signal(SIGWINCH, sl_sig_hendler);
// 	signal(SIGINT, sl_sig_hendler);
// 	signal(SIGCONT, sl_sig_hendler);
// 	signal(SIGTSTP, sl_sig_hendler);
// 	signal(SIGABRT, sl_sig_hendler);
// 	signal(SIGSTOP, sl_sig_hendler);
// 	signal(SIGKILL, sl_sig_hendler);
// 	signal(SIGQUIT, sl_sig_hendler);
// }

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
// 	// if (sig == SIGWINCH)
// 	// 	sl_print_all();
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
	print_to_terminal(input);
	initial_select(&g_evil, len);
	main_loop();
	return (0);
}

// bonus: colors, dynamic search;