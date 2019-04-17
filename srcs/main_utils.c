/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:46:08 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 13:45:14 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	restore_terminal(t_global *global)
{
	tcsetattr(INPUT_FD, TCSANOW, &global->initial_terminal_state);
	// ft_putstr_fd(global->terminal_state.cl, INPUT_FD);
	tputs(tgetstr("ve", NULL), 1, print_key);
	tputs(tgetstr("te", NULL), 1, print_key);
}

void	main_loop(void)
{
	int key;

	while ('*')
	{
		key = 0;
		if (read(0, &key, 8) == -1)
			exit(0);
		key_selection(key, &g_evil);
	}
}
