/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:16:14 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 22:46:23 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_to_terminal(t_input *input)
{
	while (input)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), input->x, input->y), OUTPUT_FD /* file descriptor, define it */);
		ft_putstr_fd(input->data, OUTPUT_FD);
		input = input->next;
	}
}
