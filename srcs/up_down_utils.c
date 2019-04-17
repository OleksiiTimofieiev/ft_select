/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:13:49 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:18:21 by otimofie         ###   ########.fr       */
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

t_input	*last_row_start(int words_per_line, int quantity_of_words)
{
	int		len;
	t_input	*res;

	len = quantity_of_words;
	res = g_evil.head;
	--len;
	while (len % words_per_line != 0)
	{
		--len;
	}
	while (len)
	{
		res = res->next;
		--len;
	}
	return (res);
}

t_input	*last_row_start_not(int words_per_line, int quantity_of_words)
{
	int		len;
	t_input	*res;

	len = quantity_of_words;
	res = g_evil.head;
	len -= words_per_line;
	while (len % words_per_line != 0)
		--len;
	if (len <= 0)
		len = words_per_line;
	while (len)
	{
		res = res->next;
		--len;
	}
	return (res);
}

void	null_the_pointers(t_input *input)
{
	while (input)
	{
		input->pointer_down = NULL;
		input->pointer_up = NULL;
		input->row_detect = 0;
		input = input->next;
	}
}

t_input	*get_end_ptr(t_input *input)
{
	while (input->next)
		input = input->next;
	return (input);
}
