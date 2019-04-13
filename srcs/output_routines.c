/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:16:14 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/12 17:40:18 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_to_terminal(t_input *input)
{
	while (input)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), input->x, input->y), OUTPUT_FD);
		ft_putstr_fd(input->data, OUTPUT_FD);
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
			ft_putstr_fd(buf, INPUT_FD);
			free(buf);
			buf = NULL;
		}
			input = input->next;
	}
}
