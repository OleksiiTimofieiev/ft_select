/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_key_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:11:42 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 17:26:27 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	null_logic(t_global *global)
{
	int		i;
	t_input *buf;

	if (global->current->next == NULL && !global->current->pointer_down)
		global->current = global->head;
	else
	{
		i = global->words_per_line;
		buf = global->current;
		while (i--)
		{
			if (global->current->next == NULL)
			{
				if (buf->pointer_down)
					global->current = buf->pointer_down;
				else
					global->current = global->head;
				break ;
			}
			global->current = global->current->next;
		}
	}
}

static void	print_result(t_global *global, t_colors colors)
{
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
		global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
}

void		down_key_handler(t_global *global)
{
	struct winsize	w;
	int				quantity_of_words;
	int				words_per_line;
	t_colors		colors;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	quantity_of_words = quantity_words_local(global->head);
	words_per_line = w.ws_col / (global->longest + SPACES);
	if (quantity_of_words <= words_per_line)
	{
		right_key_handler(global);
		return ;
	}
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
	null_logic(global);
	print_result(global, colors);
}
