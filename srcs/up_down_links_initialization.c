/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_links_initialization.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:45:30 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/16 19:06:47 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		quantity_words(t_input *input)
{
	int i;

	i = 0;
	while (input)
	{
		++i;
		input = input->next;
	}
	return (i);
}

t_input *last_row_start(int words_per_line, int quantity_of_words)
{
	int len = quantity_of_words;
	t_input *res = g_evil.head;

	// len -= 1;
	--len;
	while (len % words_per_line != 0)
	{
		--len;
	}

	// ft_putstr_fd(ft_itoa(len), 0);

	// len -= 1;
	while (len)
	{
		// ft_putstr_fd(res->data, 0);
		// ft_putstr_fd("\n", 0);

		res = res->next;
		--len;
	}
	return (res);

}

t_input *last_row_start_not(int words_per_line, int quantity_of_words)
{
	int len = quantity_of_words;
	t_input *res = g_evil.head;

	// len -= 1;
	len -= words_per_line;
	while (len % words_per_line != 0)
	{
		--len;
	}

	if (len <= 0)
		len = words_per_line;
	// ft_putstr_fd(ft_itoa(len), 0);

	// len -= 1;
	while (len)
	{
		// ft_putstr_fd(res->data, 0);
		// ft_putstr_fd("\n", 0);

		res = res->next;
		--len;
	}
	return (res);
}

void	null_the_pointers(t_input *input)
{
	while(input)
	{
		input->pointer_down = NULL;
		input->pointer_up = NULL;
		input->row_detect = 0;
		input = input->next;
	}
}

t_input *get_end_ptr(t_input *input)
{
	while (input->next)
	{
		input = input->next;
	}
	return (input);
}

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
	int quantity = words_per_line - j;
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