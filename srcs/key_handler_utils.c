/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:54:07 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:58:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	init_color_data(t_colors *colors)
{
	colors->color1 = EMPTY_COLOR;
	colors->color2 = EMPTY_COLOR;
	colors->color3 = EMPTY_COLOR;
	colors->color4 = RESET;
}

void	ft_putstr_fd_select(t_colors *colors, int fd, t_global *global)
{
	int i;

	i = 0;
	ft_putstr_fd(colors->color1, 0);
	ft_putstr_fd(colors->color2, 0);
	ft_putstr_fd(colors->color3, 0);
	ft_putstr_fd(global->current->color, 0);
	ft_putstr_fd(global->current->color_type, 0);
	ft_putstr_fd(colors->color3, 0);
	while (colors->data[i] != '\0')
	{
		write(fd, &colors->data[i], 1);
		i++;
	}
	ft_putstr_fd(colors->color4, 0);
}

int		quantity_words_local(t_input *input)
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

void	change_of_longest(t_input *input)
{
	int max;
	int len;

	max = 0;
	len = 0;
	while (input)
	{
		len = ft_strlen(input->data);
		if (len > max)
			max = len;
		input = input->next;
	}
	g_evil.longest = max;
}
