/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 15:05:54 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// TODO: norminette in all directories;

int		main(int argc, char **argv)
{
	int				len;
	t_input			*input;

	// ft_putstr_fd("main\n", 0);
	init_terminal(g_evil.termtype);
	init_data(--argc, argv, &input, &len);
	init_coordinates(&input, len);
	init_color(input);
	init_terminal_state(&g_evil, input, len);
	init_signals();
	print_to_terminal(input);
	init_up_down(&g_evil);
	main_loop();
	return (0);
}
