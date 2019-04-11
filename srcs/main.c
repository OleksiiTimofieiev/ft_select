/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 14:58:47 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		main(int argc, char **argv)
{
	t_input *input;

	ft_printf("len -> %d\n", init_data(--argc, argv, &input));

	t_input *buf = input;

	// t_input *del = input->next;

	// delete_node(&input, del);

	while (buf)
	{
		ft_printf("%s\n", buf->data);
		buf = buf->next;
	}

	ft_printf("\n");
	system("leaks -q ft_select");
	return (0);
}
