/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:32:11 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 17:28:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	up_key_handler(t_global *global)
{
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);

	int quantity_of_words = quantity_words_local(global->head);
	int words_per_line = w.ws_col / (global->longest + SPACES);

	if (quantity_of_words <= words_per_line)
	{
		left_key_handler(global);
		return;
	}

	t_input *end;
	t_colors colors;

	end = global->current;
	while (end->next)
		end = end->next;

	init_color_data(&colors);
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
			global->current->x, global->current->y), INPUT_FD);

	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0, global);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0, global);
	}

	int i = global->words_per_line;
	int null_detected = 0;
	t_input *buf = global->current;
	while (i--)
	{
		if (global->current->prev == NULL)
		{
			// global->current = end;
			null_detected = 1;
			break;
		}
		global->current = global->current->prev;
	}
	if (null_detected && buf->pointer_up)
		global->current = buf->pointer_up;
	else if (null_detected)
		global->current = end;
		
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
}
