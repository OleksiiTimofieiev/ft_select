/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_links_initialization.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:45:30 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:14:05 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


void	init_up_down(t_global *global)
{
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);

	int quantity_of_words = quantity_words(global->head);
	int words_per_line  = w.ws_col / (global->longest + SPACES);


	// ft_putstr_fd(ft_itoa(quantity_of_words), 0);
	// ft_putstr_fd("->", 0);

		// ft_putstr_fd(ft_itoa(words_per_line), 0);

	if (quantity_of_words <= words_per_line)
		return ;

	// int height = tgetnum("li");

	null_the_pointers(global->head);
	init_row_ends(global->head);

		// ft_putstr_fd(ft_itoa(quantity_of_words), 0);
		// ft_putstr_fd(ft_itoa(words_per_line), 0);

		if (quantity_of_words % words_per_line == 0)
		{
			t_input *last_row_start_pointer = last_row_start(words_per_line, quantity_of_words);

			// ft_putstr_fd(last_row_start_pointer->data, 0);

		t_input *head_start = g_evil.head->next;
		t_input *end_start = last_row_start_pointer;

		int j = words_per_line - 1;

		while(j != 0)
		{
			end_start->pointer_down = head_start;

			head_start->pointer_up = end_start;

				j--;
			end_start =end_start->next;
			head_start = head_start->next;

		}
	}
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
		// ft_putstr_fd(end->data, 0);

	// ft_putstr_fd(ft_itoa(last_row_words_quantity), 0);

// separate func

	t_input *head_start = g_evil.head->next;

	// ft_putstr_fd(head_start->data, 0);
	// t_input *end_start = end;
	int buf = last_row_words_quantity;
	while (last_row_words_quantity)
	{

		end->pointer_down = head_start;

// 		ft_putstr_fd(end->data, 0);
		// ft_putstr_fd(" ->", 0);
// 		ft_putstr_fd(head_start->data, 0);
// // 
		head_start->pointer_up = end;

		head_start = head_start->next;

		end = end->next;
		last_row_words_quantity--;
	}

	// if not two lines;

	t_input *previous_to_last_row = last_row_start_not(words_per_line, quantity_of_words);

	// ft_putstr_fd(ft_itoa(buf), 0);
	int j = 0;
	while (buf && previous_to_last_row->next)
	{
		previous_to_last_row = previous_to_last_row->next;
		buf--;
		j++;
	}

	end = previous_to_last_row;
	// ft_putstr_fd(end->data, 0);


	// ft_putstr_fd(head_start->data, 0);
	int quantity = words_per_line - j - 1;
	// ft_putstr_fd(ft_itoa(quantity), 0);

	// head_start = head_start->next;

	while (quantity-- && head_start->next && end->next)
	{
		end->pointer_down = head_start;
		head_start->pointer_up = end;

		head_start = head_start->next;
		end = end->next;
		
	}

	// ft_putstr_fd(ft_itoa(1), 0);

	// ft_putstr_fd(end->data, 0);

	// ft_putstr_fd(head_start->data, 0);

	// 	t_input *last_row_start_pointer = last_row_start_not(words_per_line, quantity_of_words);

	// last_row_start_pointer = last_row_start_pointer->next;

	// t_input *head_start = g_evil.head->next;
	// t_input *end = get_end_ptr(g_evil.head);

	// end->pointer_up = head_start;
	// head_start = head_start->next;

	// t_input *end_start = last_row_start_pointer;

	// int j = words_per_line - 2;

	// while (j != 0)
	// {
	// 	end_start->pointer_down = head_start;

	// 	head_start->pointer_up = end_start;

	// 	j--;
	// 	end_start = end_start->next;
	// 	head_start = head_start->next;
	// }
}



}