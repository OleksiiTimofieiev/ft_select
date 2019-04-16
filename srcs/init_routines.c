/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:45:27 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/16 19:19:47 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		init_data(int argc, char **argv, t_input **input, int *output_len)
{
	int	max;
	int len;

	// ft_putstr_fd("********************", 0);

	if (argc < 1)
		print_error("Invalid usage.\nCorrect usage: ./ft_select arg1 ... n ");
	max = 0;
	len = 0;
	while (argc != 0)
	{
		add_node(input, argv[argc]);
		len = ft_strlen(argv[argc]);
		if (len > max)
			max = len;
		argc--;
	}
	*output_len = max;
}

void	init_terminal(char *termtype)
{
	int res;
	
	if (!isatty(INPUT_FD))
		print_error("Not a terminal");
	else if (!(termtype = getenv("TERM")))
		print_error("TERM var is not available");
	res = tgetent(0, termtype);
	if (res < 0)
		print_error("Can not access to the terminal database");
	else if (res == 0)
		print_error("Terminal type is not defined");
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

void	init_termcap(t_termcap_cmd *tc_cmd)
{
	tc_cmd->cl = tgetstr("cl", NULL); // window
	tc_cmd->cm = tgetstr("cm", NULL); // cursor;
	tc_cmd->vi = tgetstr("vi", NULL);
	tc_cmd->ti = tgetstr("ti", NULL);
	tc_cmd->ve = tgetstr("ve", NULL);
	tc_cmd->ti = tgetstr("te", NULL);
}

void init_coordinates(t_input **input, int len)
{
	// ft_printf("len -> %d\n", len);

	struct winsize	w;
	// int height = tgetnum("li");
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);

	// ft_putstr_fd(ft_itoa(w.ws_row), INPUT_FD);
	// ft_putstr_fd("<- height **** width ->", INPUT_FD);

// 
	// ft_putstr_fd(ft_itoa(w.ws_col), INPUT_FD);




	


	// ft_putstr_fd("ft_itoa(width)", INPUT_FD);

	// int width = tgetnum("co");
	// ft_putstr_fd(ft_itoa(width), INPUT_FD);

	int word_per_line = w.ws_col / (len + SPACES);

	// ft_printf("words_per_line -> %d\n", word_per_line);
	set_coordinates(*input, word_per_line, len);

	// while(*input)
	// {
	// 	ft_printf("x = %d, y = %d\n", (*input)->x, (*input)->y);
	// 		input = &(*input)->next;
	// }

	// int x = 0;
}
