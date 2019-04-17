/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handlers_small_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:02:55 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 17:04:55 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	return_key_handler(t_global *global)
{
	restore_terminal(global);
	print_selection(global->head);
	exit(0);
}

void	delete_key_handler(t_global *global)
{
	t_colors colors;

	delete_node(&global->head, global->current, global->longest, global);
	init_color_data(&colors);
	colors.data = global->current->data;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
		global->current->y), INPUT_FD);
	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0, global);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0, global);
	}
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
		global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
	change_of_longest(g_evil.head);
	init_up_down(&g_evil);
}
