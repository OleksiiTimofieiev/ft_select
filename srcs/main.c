/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 13:57:01 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/16 13:42:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

// TODO: norminette in all directories;
// TODO: check static ones to local funcs;

// TODO: arrows to the next // previous column;

int		main(int argc, char **argv)
{
	int				len;
	t_input 		*input;

// int i =1;

// while(argv[i])
// {
// 	ft_putstr_fd(argv[i++], 0);
// 	ft_putstr_fd("\n", 0);
// }


	init_terminal(g_evil.termtype);
	init_data(--argc, argv, &input, &len);
	init_coordinates(&input, len);
	init_color(input);
	init_terminal_state(&g_evil, input, len);
	init_signals();
	print_to_terminal(input);
	// initial_select(&g_evil, len);
	init_up_down(&g_evil);

	main_loop();
	return (0);
}

// bonus: colors, dynamic search;