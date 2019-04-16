/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_row_ends.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 15:03:53 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/16 15:40:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_row_ends(t_input *input)
{
	int				i;
	struct winsize	w;
	int				words_per_line;

	i = 0;
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	words_per_line = w.ws_col / (g_evil.longest + SPACES);
	while (input)
	{
		if (i == words_per_line)
		{
			input->row_detect = 1;
ft_putstr_fd(input->data, 0);
			i = 1;
		}
		input = input->next;
		i++;
	}
}
