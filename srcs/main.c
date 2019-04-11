/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 18:58:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// TODO: norminette;
// TODO: leaks => delete all data before exit => OS will clean it;

void	print_to_terminal(t_input *input)
{
	while (input)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), input->x, input->y), 0 /* file descriptor, define it */);
		ft_printf("%s", input->data);
		input = input->next;
	}
}

int main(int argc, char **argv)
{
		t_termcap_cmd	tc_cmd;
		char			*termtype = NULL;
		t_input			*input = NULL;
		int				len;
		struct termios s_termios;
		struct termios s_termios_backup;

		init_data(--argc, argv, &input, &len);
		init_terminal(termtype);
		init_coordinates(&input, len);
		init_termcap(&tc_cmd);


		if (tcgetattr(0, &s_termios) == -1)
			return (-1);

		if (tcgetattr(0, &s_termios_backup) == -1)
			return (-1);

		s_termios.c_lflag &= ~(ICANON); /* Перевести терминал в канонический режим. Функция чтения будет получать ввод с клавиатуры без ожидания ввода */
		s_termios.c_lflag &= ~(ECHO);   /* Клавиши, набранные на клавиатуре, больше не будут появляться в терминале */

		ft_putstr_fd(tc_cmd.cl, 0); // clear window
		ft_putstr_fd(tc_cmd.vi, 0); // mask cursor

		int i = 1000000000;

		print_to_terminal(input);

		while (i--)
			;

		ft_putstr_fd(tc_cmd.cl, 0); // clear window

		// t_input *buf = input;

		t_input *del = input->next;

		delete_node(&input, del, len);

		while (i--)
			;

		ft_putstr_fd(tc_cmd.ve, 0);


		// while (buf)
		// {
		// 	ft_printf("%s\n", buf->data);
		// 	buf = buf->next;
		// }

		ft_printf("\n");
		system("leaks -q ft_select");
		return (0);
}
