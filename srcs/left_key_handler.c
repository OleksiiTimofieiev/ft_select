/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_key_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:05:38 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 17:11:16 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static	t_input	*local_end(t_global *global)
{
	t_input *end;

	end = global->current;
	while (end->next)
		end = end->next;
	return (end);
}

void			left_key_handler(t_global *global)
{
	t_input		*end;
	t_colors	colors;

	init_color_data(&colors);
	end = local_end(global);
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
		global->current->x, global->current->y), INPUT_FD);
	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0, global);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0, global);
	}
	if (global->current->prev == NULL)
		global->current = end;
	else
		global->current = global->current->prev;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
		global->current->x, global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
}
