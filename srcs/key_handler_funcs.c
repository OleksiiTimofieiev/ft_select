/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:32:11 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/12 19:21:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void ft_putstr_fd_select(t_colors *colors, int fd)
{
	int i;

	i = 0;
	ft_putstr_fd(colors->color1, 0);
	ft_putstr_fd(colors->color2, 0);
	ft_putstr_fd(colors->color3, 0);

	while (colors->data[i] != '\0')
	{
		write(fd, &colors->data[i], 1);
		i++;
	}
	ft_putstr_fd(colors->color4, 0);
}

void	esc_key_handler(t_global *global)
{
	restore_terminal(global);
	exit(0);
}

void init_color_data(t_colors *colors)
{
	colors->color1 = EMPTY_COLOR;
	colors->color2 = EMPTY_COLOR;
	colors->color3 = EMPTY_COLOR;
	colors->color4 = RESET;
}

void down_key_handler(t_global *global)
{
	t_colors colors;
	
	init_color_data(&colors);
	colors.data = global->current->data;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					global->current->y), OUTPUT_FD);
	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0);
	}
	if (global->current->next == NULL)
		global->current = global->head;
	else
		global->current = global->current->next;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					global->current->y), OUTPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC,
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0);
}

void	up_key_handler(t_global *global)
{
	t_input *end;
	t_colors colors;

	init_color_data(&colors);
	colors.data = global->current->data;
	end = global->current;
	while (end->next)
		end = end->next;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
			global->current->x, global->current->y), OUTPUT_FD);
	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0);
	}
	if (global->current->prev == NULL)
		global->current = end;
	else
		global->current = global->current->prev;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
		global->current->x, global->current->y), OUTPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0);
}

void	space_key_handler(t_global *global)
{
	t_colors colors;

	init_color_data(&colors);
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
		global->current->x, global->current->y), OUTPUT_FD);
	if (global->current->selection == 0)
	{
		global->current->selection = 1;
colors.color1 = BACK;
colors.color2 = UNDERLINED;
colors.color3 = ITALIC;

ft_putstr_fd_select(&colors, 0);
	}
	else
	{
		global->current->selection = 0;
		colors.color1 = EMPTY_COLOR;
		colors.color2 = UNDERLINED;
		colors.color3 = ITALIC;
		ft_putstr_fd_select(&colors, 0);
	}
	down_key_handler(global);
}

void	select_all(t_global *global)
{
	t_input *buf;
	
	buf = global->head;
	while (buf)
	{
		buf->selection = 1;
		down_key_handler(global);
		buf = buf->next;
	}
}
