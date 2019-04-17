/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:36:39 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 17:47:39 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_input	*iteration_1(int *last_row_words_quantity)
{
	t_input *end;

	end = get_end_ptr(g_evil.head);
	while (end)
	{
		(*last_row_words_quantity)++;
		if (end->row_detect == 1)
			break ;
		end = end->prev;
	}
	return (end);
}

void	iteration_2(int last_row_words_quantity, t_input *end,
		t_input *head_start)
{
	while (last_row_words_quantity)
	{
		end->pointer_down = head_start;
		head_start->pointer_up = end;
		head_start = head_start->next;
		end = end->next;
		last_row_words_quantity--;
	}
}

t_input	*iteration_3(int last_row_words_quantity, int words_per_line,
		int quantity_of_words)
{
	t_input	*previous_to_last_row;
	int		j;

	j = 0;
	previous_to_last_row = last_row_start_not(words_per_line,
							quantity_of_words);
	while (last_row_words_quantity && previous_to_last_row->next)
	{
		previous_to_last_row = previous_to_last_row->next;
		last_row_words_quantity--;
		j++;
	}
	return (previous_to_last_row);
}

void	if_mod_not_equals_zero(int words_per_line, int quantity_of_words)
{
	int		last_row_words_quantity;
	t_input	*end;
	t_input *head_start;
	int		quantity;

	last_row_words_quantity = 0;
	end = iteration_1(&last_row_words_quantity);
	head_start = g_evil.head->next;
	iteration_2(last_row_words_quantity, end, head_start);
	end = iteration_3(last_row_words_quantity, words_per_line,
						quantity_of_words);
	quantity = words_per_line - j - 1;
	while (quantity-- && head_start->next && end->next)
	{
		end->pointer_down = head_start;
		head_start->pointer_up = end;
		head_start = head_start->next;
		end = end->next;
	}
}
