/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:16:14 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 15:00:40 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		validata_screen_size(void)
{
	struct winsize	w;
	t_input			*buf;
	int				i;
	int				word_per_line;
	int				necessary_quantity_of_rows;

	i = 0;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	buf = g_evil.head;
	while (buf)
	{
		buf = buf->next;
		i++;
	}
	i++;
	word_per_line = w.ws_col / (g_evil.longest + SPACES);
	necessary_quantity_of_rows = i / word_per_line;
	if (necessary_quantity_of_rows >= w.ws_row)
		return (0);
	else
		return (1);
}

void	print_to_terminal(t_input *input)
{
	ft_putstr_fd(g_evil.terminal_state.cl, INPUT_FD);
	if (!validata_screen_size())
	{
		ft_putstr_fd("Window size is too small.", INPUT_FD);
		return ;
	}
	while (input)
	{
		tputs(tgoto(tgetstr("cm", NULL), input->x, input->y), 1, print_key);
		if (input->selection == 1)
			ft_putstr_fd(BACK, INPUT_FD);
		ft_putstr_fd(input->color_type, INPUT_FD);
		ft_putstr_fd(input->color, INPUT_FD);
		ft_putstr_fd(input->data, INPUT_FD);
		ft_putstr_fd(RESET, INPUT_FD);
		input = input->next;
	}
	initial_select(&g_evil, g_evil.longest);
}

void	print_selection(t_input *input)
{
	char	*buf;
	int		len;

	buf = NULL;
	while (input)
	{
		if (input->selection == 1)
		{
			len = ft_strlen(input->data);
			buf = (char *)malloc(sizeof(char) * (len + 2));
			ft_strcpy(buf, input->data);
			buf[len] = 32;
			buf[len + 1] = '\0';
			ft_putstr_fd(buf, OUTPUT_FD);
			free(buf);
			buf = NULL;
		}
		input = input->next;
	}
}

int		print_key(int n)
{
	return (write(INPUT_FD, &n, 1));
}
