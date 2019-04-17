/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_links_initialization.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:45:30 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:34:40 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	if_mod_equals_zero(int words_per_line, int quantity_of_words)
{
	t_input *last_row_start_pointer;
	t_input *head_start;
	t_input *end_start;
	int j;

		last_row_start_pointer = last_row_start(words_per_line, quantity_of_words);
	head_start = g_evil.head->next;
	end_start = last_row_start_pointer;

	j = words_per_line - 1;

	while (j != 0)
	{
		end_start->pointer_down = head_start;

		head_start->pointer_up = end_start;

		j--;
		end_start = end_start->next;
		head_start = head_start->next;
	}
}

void	init_up_down(t_global *global)
{
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);

	int quantity_of_words = quantity_words(global->head);
	int words_per_line  = w.ws_col / (global->longest + SPACES);

	if (quantity_of_words <= words_per_line)
		return ;

	null_the_pointers(global->head);
	init_row_ends(global->head);

	if (quantity_of_words % words_per_line == 0)
		if_mod_equals_zero(words_per_line, quantity_of_words);
else
{
	int last_row_words_quantity = 0;
	t_input *end = get_end_ptr(g_evil.head);

	while (end)
	{
		last_row_words_quantity++;
		if (end->row_detect == 1)
			break ;
		end = end->prev;
	}

	t_input *head_start = g_evil.head->next;

	int buf = last_row_words_quantity;

	while (last_row_words_quantity)
	{

		end->pointer_down = head_start;
		head_start->pointer_up = end;
		head_start = head_start->next;
		end = end->next;
		last_row_words_quantity--;
	}

	t_input *previous_to_last_row = last_row_start_not(words_per_line, quantity_of_words);


	int j = 0;
	while (buf && previous_to_last_row->next)
	{
		previous_to_last_row = previous_to_last_row->next;
		buf--;
		j++;
	}

	end = previous_to_last_row;

	int quantity = words_per_line - j - 1;

	while (quantity-- && head_start->next && end->next)
	{
		end->pointer_down = head_start;
		head_start->pointer_up = end;

		head_start = head_start->next;
		end = end->next;
		
	}
}



}