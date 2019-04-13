/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:46:08 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 20:38:41 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	restore_terminal(t_global *global)
{
	tcsetattr(OUTPUT_FD, TCSANOW, &global->initial_terminal_state);
	ft_putstr_fd(global->terminal_state.te, OUTPUT_FD);
	ft_putstr_fd(global->terminal_state.ve, OUTPUT_FD);
	ft_putstr_fd(global->terminal_state.cl, OUTPUT_FD);
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
