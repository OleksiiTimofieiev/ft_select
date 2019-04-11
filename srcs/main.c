/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 16:37:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_terminal(char *termtype)
{
	int res;
	
	termtype = getenv("TERM");
	res = tgetent(0, termtype);
}

void	set_coordinates(t_input *input, int word_per_line, int len)
{
	int y; 
	int i; 
	int x_tmp; 

	y = 0;
	i = 0;
	x_tmp = 0;
	while (input)
	{
		if (i++ < word_per_line)
		{
			input->x = x_tmp;
			input->y = y;
			x_tmp += (len + SPACES);
		}
		else
		{
			x_tmp = 0;
			input->x = x_tmp;
			x_tmp += (len + SPACES);
			input->y = ++y;
			i = 1;
		}
		input = input->next;
	}
}

void	init_coordinates(int argc, char **argv, t_input **input)
{
	int len = init_data(--argc, argv, input);
	// ft_printf("len -> %d\n", len);

	// int height = tgetnum("li");
	// ft_printf("height -> %d\n", height);

	// int width = tgetnum("co");
	// ft_printf("width -> %d\n", width);

	int word_per_line = tgetnum("co") / (len + SPACES);

	// ft_printf("words_per_line -> %d\n", word_per_line);
	set_coordinates(*input, word_per_line, len);

// while(*input)
// {
// 	ft_printf("x = %d, y = %d\n", (*input)->x, (*input)->y);
// 		input = &(*input)->next;
// }


	// int x = 0;

}

struct s_termcap_cmd
{
	char *cl;
	char *cm;
	char *vi;
	char *ve;
	char *ab;
	char *reset;

	char *ku;
	char *kd;
	char *kl;
	char *kr;
};
struct s_termcap_cmd tc_cmd;

void init_termcap(struct s_termcap_cmd *tc_cmd)
{
	// #ifdef USE_TERMCAP




	tc_cmd->cl = tgetstr("cl", NULL); // window
	tc_cmd->cm = tgetstr("cm", NULL); // cursor;
	tc_cmd->vi = tgetstr("vi", NULL);
	tc_cmd->ve = tgetstr("ve", NULL);
	tc_cmd->ab = tgetstr("AB", NULL);
	tc_cmd->reset = tgetstr("me", NULL);

	tc_cmd->ku = tgetstr("ku", NULL);
	tc_cmd->kd = tgetstr("kd", NULL);
	tc_cmd->kl = tgetstr("kl", NULL);
	tc_cmd->kr = tgetstr("kr", NULL);
}

void	print_to_terminal(t_input *input)
{
	while(input)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), input->x, input->y), 0 /* file descriptor, define it */);
		ft_printf("%s", input->data);
		input = input->next;
	}

}

int main(int argc, char **argv)
{
		char *termtype = NULL;
		t_input *input = NULL;

		init_terminal(termtype);
		init_coordinates(argc, argv, &input);
		init_termcap(&tc_cmd);

		struct termios s_termios;
		struct termios s_termios_backup;

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



		
		ft_putstr_fd(tc_cmd.ve, 0);

		// t_input *buf = input;

		// t_input *del = input->next;

		// delete_node(&input, del);

		// while (buf)
		// {
		// 	ft_printf("%s\n", buf->data);
		// 	buf = buf->next;
		// }

		ft_printf("\n");
		system("leaks -q ft_select");
		return (0);
}
