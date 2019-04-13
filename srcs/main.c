/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 20:28:11 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// TODO: norminette in all directories;
// TODO: check static ones;

// TODO: arrows to the next // previous column;

/* 3 */
// TODO: large vs small window;
// TODO: The cursor of selection must be repositioned in a reasonable manner after a resizing.
// TODO: # define NO_ROOM "Not enough space! Resize window."
// TODO: not possible to show everithing; if size is ok -> show everithing;
// TODO: check how the change size signal works; on every move = +;
// TODO: Whichever way your program ends, the default configuration of your terminal MUST be restored. This is true even after it received a signal (except for the signals that we cannot intercept, but this would mean that your program does not work).
// TODO: We must be able to interrupt your program with ctrl+z and restore it with fg without seeing any changes in its behavior.
// TODO: correction form

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
// 		exit(0);
// }

int		main(int argc, char **argv)
{
	char			*termtype;
	t_input			*input;
	int				len;

	termtype = NULL;
	input = NULL;
	init_terminal(termtype);
	init_data(--argc, argv, &input, &len);
	init_coordinates(&input, len);
	init_termcap(&g_evil.terminal_state);
	init_color(input);
	init_terminal_state(&g_evil, input, len);
	print_to_terminal(input);
	initial_select(&g_evil, len);
	main_loop();

	return (0);
}
