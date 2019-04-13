/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 18:35:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// TODO: norminette in all directories;
// TODO: check static ones;

/* 1 */
/* 2 */

// TODO: arrows to the next // previous column;

/* 3 */
// TODO: large vs small window;
// TODO: The cursor of selection must be repositioned in a reasonable manner after a resizing.
// TODO: resize of the window => cursor behavioiur
// TODO: # define NO_ROOM "Not enough space! Resize window."
// TODO: not possible to show everithing; if size is ok -> show everithing;
// TODO: check how the change size signal works; on every move = +;
// TODO: Whichever way your program ends, the default configuration of your terminal MUST be restored. This is true even after it received a signal (except for the signals that we cannot intercept, but this would mean that your program does not work).
// TODO: We must be able to interrupt your program with ctrl+z and restore it with fg without seeing any changes in its behavior.

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

void 	restore_terminal(t_global *global)
{
	tcsetattr(OUTPUT_FD, TCSANOW, &global->initial_terminal_state);
	ft_putstr_fd(global->terminal_state.te, OUTPUT_FD);
	ft_putstr_fd(global->terminal_state.ve, OUTPUT_FD);
	ft_putstr_fd(global->terminal_state.cl, OUTPUT_FD); // clear window
}

// t_some_struct *ss(void)
// {
// 	static t_some_struct ss;

// 	return (&ss);
// }

// t_some_struct *ss;

// ss = ss(ksdjfhg);
// ss->
// ss()->
// 	->asdads








int		main(int argc, char **argv)
{
		
		char			*termtype = NULL;
		t_input			*input = NULL;
		int				len;

		init_terminal(termtype);
		init_data(--argc, argv, &input, &len);
		init_coordinates(&input, len);
		init_termcap(&g_evil.terminal_state); // init_global
		init_color(input);

			g_evil.head = input;
		g_evil.current = input;

		if (tcgetattr(OUTPUT_FD, &g_evil.initial_terminal_state) == -1)
			return (-1);
		if (tcgetattr(OUTPUT_FD, &g_evil.new_terminal_state) == -1)
			return (-1);

		// if (tcgetattr(0, &global.new_terminal_state) == -1)
		// 	return (-1);

		g_evil.new_terminal_state.c_lflag &= ~(ICANON | ECHO); /* Перевести терминал в канонический режим. Функция чтения будет получать ввод с клавиатуры без ожидания ввода */
		// g_evil.initial_terminal_state.c_lflag &= ~(ECHO);   /* Клавиши, набранные на клавиатуре, больше не будут появляться в терминале */
			g_evil.initial_terminal_state.c_cc[VMIN] = 1;
			g_evil.initial_terminal_state.c_cc[VTIME] = 0;

		tcsetattr(OUTPUT_FD, TCSANOW, &g_evil.new_terminal_state);

		ft_putstr_fd(g_evil.terminal_state.ti, OUTPUT_FD); // 
		ft_putstr_fd(g_evil.terminal_state.vi, OUTPUT_FD); // mask cursor
		ft_putstr_fd(g_evil.terminal_state.cl, OUTPUT_FD); // clear window

		g_evil.longest = len;
		print_to_terminal(input);
		initial_select(&g_evil, len);

		int key;
		while (42)
		{
			key = 0;
			if (read(0, &key, 8) == -1)
			// {
				// ft_putstr_fd("asdfasdfasdfadsf", 0);	
				exit(0);
			// }
			// ft_putstr_fd(ft_itoa(key), 0);
			key_selection(key, &g_evil);
		}



		// ft_putstr_fd(global.terminal_state.cl, OUTPUT_FD); // clear window

		// ft_putstr_fd("includes ", INPUT_FD);
		


		// ft_printf("\n");
		// ft_putstr_fd(terminal_state.cl, OUTPUT_FD); // clear window


		return (0);
}
