/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:45:27 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 18:49:16 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		init_data(int argc, char **argv, t_input **input, int *output_len)
{
	int	max;
	int len;

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

void	init_termcap(t_termcap_cmd *tc_cmd)
{
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

void init_coordinates(t_input **input, int len)
{
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

