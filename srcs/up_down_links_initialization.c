/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_links_initialization.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 16:45:30 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/15 16:57:36 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		quantity_words(t_input *input)
{
	int i;

	i = 0;
	while (input)
	{
		i++;
		input = input->next;
	}
	return (i);
}

t_input *last_row_start(t_input *input)
{
	int
}

void	init_up_down(t_global *global)
{
	struct winsize w;
	// int height = tgetnum("li");
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);

	int quantity_of_words = quantity_words(global->head);
	int words_per_line  = w.ws_col / (global->longest + SPACES);

	ft_putstr_fd(ft_itoa(quantity_of_words), 0);
	ft_putstr_fd(ft_itoa(words_per_line), 0);

	if (quantity_of_words % words_per_line == 0)
	{
		t_input *last_row_start = 
	}
}