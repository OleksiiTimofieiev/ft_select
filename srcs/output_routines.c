/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:16:14 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 21:54:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_to_terminal(t_input *input)
{
	ft_putstr_fd(g_evil.terminal_state.cl, INPUT_FD);
	while (input)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), input->x, input->y), INPUT_FD);
		if (input->selection == 1)
			ft_putstr_fd(BACK, INPUT_FD);
		ft_putstr_fd(input->color_type, INPUT_FD);
		ft_putstr_fd(input->color, INPUT_FD);
		ft_putstr_fd(input->data, INPUT_FD);
		ft_putstr_fd(RESET, INPUT_FD);
		input = input->next;
	}
}

void	print_selection(t_input *input)
{
	char *buf;
	int len;

	buf = NULL;
	while (input)
	{
		if (input->selection == 1)
		{
			len = ft_strlen(input->data);
			buf = (char *)malloc(sizeof(char) * (len + 2));
			ft_strcpy(buf, input->data);
			buf[len] = 32;
			buf[len + 1] ='\0';
			ft_putstr_fd(buf, OUTPUT_FD);
			free(buf);
			buf = NULL;
		}
		input = input->next;
	}
}
