/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:32:11 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 17:41:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_res(t_global *global, t_colors colors)
{
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
		global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
}

static void	null_logic(t_global *global, t_input *end)
{
	int		i;
	int		null_detected;
	t_input	*buf;

	null_detected = 0;
	i = global->words_per_line;
	buf = global->current;
	while (i--)
	{
		if (global->current->prev == NULL)
		{
			null_detected = 1;
			break ;
		}
		global->current = global->current->prev;
	}
	if (null_detected && buf->pointer_up)
		global->current = buf->pointer_up;
	else if (null_detected)
		global->current = end;
}

static int check(int quantity_of_words, int words_per_line, t_global *global)
{
	if (quantity_of_words <= words_per_line)
	{
		left_key_handler(global);
		return (0);
	}
	return (1);
}
void		up_key_handler(t_global *global)
{
	struct winsize	w;
	int				quantity_of_words;
	int				words_per_line;
	t_input			*end;
	t_colors		colors;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	quantity_of_words = quantity_words_local(global->head);
	words_per_line = w.ws_col / (global->longest + SPACES);
	if (!check(quantity_of_words, words_per_line, global))
		return ;
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
	null_logic(global, end);
	print_res(global, colors);
}
