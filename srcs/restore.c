/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:46:08 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 18:47:11 by otimofie         ###   ########.fr       */
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
