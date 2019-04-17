/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_links_initialization.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:45:30 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:41:11 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	if_mod_equals_zero(int words_per_line, int quantity_of_words)
{
	t_input	*last_row_start_pointer;
	t_input	*head_start;
	t_input	*end_start;
	int		j;

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
		if_mod_not_equals_zero(words_per_line, quantity_of_words);
}
