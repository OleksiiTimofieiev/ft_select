/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 15:32:51 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_terminal(char *termtype)
{
	int res;
	
	termtype = getenv("TERM");
	res = tgetent(0, termtype);
}

void	init_coordinates(int argc, char **argv, t_input **input)
{
	int len = init_data(--argc, argv, input);

	int height = tgetnum("li");
	ft_printf("height -> %d\n", height);

	int width = tgetnum("co");
	ft_printf("width -> %d\n", width);

	int word_per_line = width / (len + SPACES);

	ft_printf("words_per_line -> %d\n", word_per_line);

	
}

int		main(int argc, char **argv)
{
	char 			*termtype = NULL;
	t_input 		*input = NULL;


	init_terminal(termtype);
	init_coordinates(argc, argv, &input);

		struct termios s_termios;
	struct termios 	s_termios_backup;

	if (tcgetattr(0, &s_termios) == -1)
		return (-1);

	if (tcgetattr(0, &s_termios_backup) == -1)
		return (-1);

	// s_termios.c_lflag &= ~(ICANON); /* Перевести терминал в канонический режим. Функция чтения будет получать ввод с клавиатуры без ожидания ввода */
	// s_termios.c_lflag &= ~(ECHO);   /* Клавиши, набранные на клавиатуре, больше не будут появляться в терминале */



	t_input *buf = input;

	t_input *del = input->next;

	delete_node(&input, del);

	while (buf)
	{
		ft_printf("%s\n", buf->data);
		buf = buf->next;
	}

	ft_printf("\n");
	system("leaks -q ft_select");
	return (0);
}
