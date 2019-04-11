/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_routines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:16:14 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 20:16:39 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_to_terminal(t_input *input)
{
	while (input)
	{
		ft_putstr_fd(tgoto(tgetstr("cm", NULL), input->x, input->y), 0 /* file descriptor, define it */);
		ft_printf("%s", input->data);
		input = input->next;
	}
}
