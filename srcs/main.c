/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 22:54:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// TODO: norminette;
// TODO: leaks => delete all data before exit => OS will clean it;

/* 1 */
/* 2 */

// tODO: struct with start and end as a pointer;
// TODO: circular selection with arrows ;
// TODO: One or more choices can be selected or un-selected with the the space key. With
// each selection, the cursor must automatically position itself on the next element.
// TODO: Cursor’s position: underlined text.
// TODO: large vs small window;
// TODO: resize of the window => cursor behavioiur
// TODO: Selected choice: inverse video text.
// TODO: Choice non selected: normal text.
// • If the choices are files names, colorize the list according to the extensions (a bit like
// ls -G on OSX).
// TODO: Selected choice + cursor’s position: inverse video underlined text.
// TODO: # define NO_ROOM "Not enough space! Resize window."
// TODO: Whichever way your program ends, the default configuration of your terminal MUST be restored. This is true even after it received a signal (except for the signals that we cannot intercept, but this would mean that your program does not work).
// TODO: If the user presses either delete or backspace, the element the cursor is pointing to must be erased from the list.
// If there are no more elements in the list, the behavior must be exactly the same as if the user had pressed esc.
// TODO: When the user validates the selection with the return key, the list of choices will be sent back to shell.
// The latter (i.e. list of choices sent back) will be separated by a space. This will allow you to use your program ft_select inside a shell script (to create a “set” for example).
// TODO: sample of commands as in the subject;
// TODO: not possible to show everithing; if size is ok -> show everithing;
// TODO: If the user presses either delete or backspaceIf there are no more elements in the list, the behavior must be exactly the same as if the user had pressed esc.

/* 3 */

// TODO: check how the change size signal works; on every move = +;
// TODO: esc handler;
// TODO: We must be able to interrupt your program with ctrl+z and restore it with fg without seeing any changes in its behavior.
// TODO: If the program is launched in an empty environment, you need to behave reasonably.

// ft_dprintf(OUTPUT_FD, "%s%s%s%~s\n",
// 		   (arg->selected ? BACK : EMPTY_STR),
// 		   (arg->chosen_one ? UNDER_LINE : EMPTY_STR),
// 		   (arg->chosen_one ? ITALIC : EMPTY_STR),
// 		   arg->color_type,
// 		   arg->color,
// 		   arg->name);

int		main(int argc, char **argv)
{
		t_termcap_cmd	terminal_state;
		char			*termtype = NULL;
		t_input			*input = NULL;
		int				len;
		struct 	termios s_termios;
		// struct termios 	s_termios_backup;

		init_terminal(termtype);
		init_data(--argc, argv, &input, &len);
		init_coordinates(&input, len);
		init_termcap(&terminal_state);

		if (tcgetattr(OUTPUT_FD, &s_termios) == -1)
			return (-1);

		// if (tcgetattr(0, &s_termios_backup) == -1)
		// 	return (-1);

		s_termios.c_lflag &= ~(ICANON | ECHO); /* Перевести терминал в канонический режим. Функция чтения будет получать ввод с клавиатуры без ожидания ввода */
		// s_termios.c_lflag &= ~(ECHO);   /* Клавиши, набранные на клавиатуре, больше не будут появляться в терминале */

		ft_putstr_fd(terminal_state.cl, OUTPUT_FD); // clear window
		ft_putstr_fd(terminal_state.vi, OUTPUT_FD); // mask cursor

		int i = 1000000000;

		print_to_terminal(input);

		while (i--)
			;

		// ft_putstr_fd(terminal_state.cl, OUTPUT_FD); // clear window

		// t_input *buf = input;

		// g_pointer = input;

		// delete_node(&input, g_pointer, len);

		// while (i--)
		// 	;

		ft_putstr_fd(terminal_state.ve, OUTPUT_FD);
		ft_putstr_fd(terminal_state.cl, OUTPUT_FD); // clear window

		// while (buf)
		// {
		// 	ft_printf("%s\n", buf->data);
		// 	buf = buf->next;
		// }
		ft_putstr_fd("includes ", INPUT_FD);
		ft_putstr_fd("srcs ", INPUT_FD);
		ft_putstr_fd("srcs ", INPUT_FD);

		// ft_printf("\n");
		// ft_putstr_fd(terminal_state.cl, OUTPUT_FD); // clear window

		// system("leaks -q ft_select");
		return (0);
}
