/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hadlers_with_small_code_size.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:58:45 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 17:01:46 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	esc_key_handler(t_global *global)
{
	restore_terminal(global);
	exit(0);
}

void	right_key_handler(t_global *global)
{
	t_colors colors;

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
	if (global->current->next == NULL)
		global->current = global->head;
	else
		global->current = global->current->next;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
		global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
}

void	space_key_handler(t_global *global)
{
	t_colors colors;

	init_color_data(&colors);
	colors.data = global->current->data;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
		global->current->x, global->current->y), INPUT_FD);
	if (global->current->selection == 0)
	{
		global->current->selection = 1;
		colors.color1 = BACK;
		colors.color2 = UNDERLINED;
		colors.color3 = ITALIC;
		ft_putstr_fd_select(&colors, 0, global);
	}
	else
	{
		global->current->selection = 0;
		colors.color1 = EMPTY_COLOR;
		colors.color2 = UNDERLINED;
		colors.color3 = ITALIC;
		ft_putstr_fd_select(&colors, 0, global);
	}
	right_key_handler(global);
}

void	select_all_handler(t_global *global)
{
	t_input *buf;

	buf = global->head;
	while (buf)
	{
		buf->selection = 1;
		down_key_handler(global);
		buf = buf->next;
	}
}

void	deselect_all_handler(t_global *global)
{
	t_input *buf;

	buf = global->head;
	while (buf)
	{
		buf->selection = 0;
		down_key_handler(global);
		buf = buf->next;
	}
}
