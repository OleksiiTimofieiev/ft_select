/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 14:45:54 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	t_input *input;

	init_data(--argc, argv, &input);

	t_input *buf = input;

	// t_input *del = input->next;

	// deleteNode(&input, del);

	while (buf)
	{
		ft_printf("%s\n", buf->data);
		buf = buf->next;
	}

	ft_printf("\n");
	system("leaks -q ft_select");
	return (0);
}
