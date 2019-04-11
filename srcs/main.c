/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 14:28:25 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	add_node(t_input **head_ref, char *data)
{
	t_input *new_node;

	new_node = (t_input *)malloc(sizeof(t_input));
	new_node->data = ft_strdup(data);
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}

void	init_data(int argc, char **argv, t_input **input)
{
	while (argc != 0)
		add_node(input, argv[argc--]);
}

int		main(int argc, char **argv)
{
	t_input *input;

	init_data(--argc, argv, &input);
	// t_input *buf = input;
	// while (buf)
	// {
	// 	ft_printf("%s\n", buf->data);
	// 	buf = buf->next;
	// }
	ft_printf("\n");
	system("leaks -q ft_select");
	return (0);
}
