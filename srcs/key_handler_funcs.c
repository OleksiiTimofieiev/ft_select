/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:32:11 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/12 16:40:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	esc_key_handler(t_global *global)
{
	restore_terminal(global);
	exit(0);
}

void 	down_key_handler(t_global *global)
{
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x, global->current->y), OUTPUT_FD /* file descriptor, define it */);
	ft_printf_fd("%s", global->current->data);
	if (global->current->next == NULL)
		global->current = global->head;
	else
		global->current = global->current->next;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x, global->current->y), OUTPUT_FD /* file descriptor, define it */);
	ft_printf_fd("%s%s%s%s", UNDERLINED, ITALIC, global->current->data, RESET);
}

void 	up_key_handler(t_global *global)
{
	t_input *end;

	end = global->current;
	while(end->next)
		end = end->next;

	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x, global->current->y), OUTPUT_FD /* file descriptor, define it */);
	ft_printf_fd("%s", global->current->data);
	if (global->current->prev == NULL)
		global->current = end;
	else
		global->current = global->current->prev;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x, global->current->y), OUTPUT_FD /* file descriptor, define it */);
	ft_printf_fd("%s%s%s%s", UNDERLINED, ITALIC, global->current->data, RESET);
}