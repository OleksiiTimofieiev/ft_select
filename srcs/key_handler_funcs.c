/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:32:11 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 21:24:27 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"


void 	init_color_data(t_colors *colors)
{
	colors->color1 = EMPTY_COLOR;
	colors->color2 = EMPTY_COLOR;
	colors->color3 = EMPTY_COLOR;
	colors->color4 = RESET;
}

void 	ft_putstr_fd_select(t_colors *colors, int fd, t_global *global)
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

void	esc_key_handler(t_global *global)
{
	restore_terminal(global);
	exit(0);
}
void	right_key_handler(t_global *global)
{
	t_colors colors;
	
	init_color_data(&colors);
	colors.data = global->current->data;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					global->current->y), INPUT_FD);
	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0, global);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0, global);
	}
	if (global->current->next == NULL)
		global->current = global->head;
	else
		global->current = global->current->next;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);

}

void    down_key_handler(t_global *global)
{
	
	int i;

	// i = global->height;

	t_colors colors;

	init_color_data(&colors);
	colors.data = global->current->data;
	
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
			global->current->x, global->current->y), INPUT_FD);

	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0, global);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0, global);
	}
	if (global->current->next == NULL)
	{
		global->current = global->head;
	}
	else
	{
	i = global->words_per_line;
	int null_detected = 0;
	t_input *buf = global->current;
	while (i--) // move backwards;
	{
		if (global->current->next == NULL)
		{
			// right_key_handler(global);
			null_detected = 1;
			break;
		}
		global->current = global->current->next;
	}
	if (null_detected)
		global->current = buf;
}
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
}

void	up_key_handler(t_global *global)
{
		
	t_input *end; /* implement a func for end */
	t_colors colors;

	end = global->current;
	while (end->next)
		end = end->next;


	init_color_data(&colors);
	colors.data = global->current->data;
	
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
			global->current->x, global->current->y), INPUT_FD);

	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0, global);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0, global);
	}

	int i = global->words_per_line;
	int null_detected = 0;
	t_input *buf = global->current;
	while (i--)
	{
		if (global->current->prev == NULL)
		{
			// global->current = end;
			null_detected = 1;
			break;
		}
		global->current = global->current->prev;
	}
	if (buf->prev && null_detected)
		global->current = buf;	
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
}

void	space_key_handler(t_global *global)
{
	t_colors colors;

	init_color_data(&colors);
	colors.data = global->current->data;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
		global->current->x, global->current->y), INPUT_FD);
	if (global->current->selection == 0)
	{
		global->current->selection = 1;
		colors.color1 = BACK;
		colors.color2 = UNDERLINED;
		colors.color3 = ITALIC;

		ft_putstr_fd_select(&colors, 0, global);
	}
	else
	{
		global->current->selection = 0;
		colors.color1 = EMPTY_COLOR;
		colors.color2 = UNDERLINED;
		colors.color3 = ITALIC;
		ft_putstr_fd_select(&colors, 0, global);
	}
	right_key_handler(global);
}

void	select_all_handler(t_global *global)
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

void	deselect_all_handler(t_global *global)
{
	t_input *buf;
	
	buf = global->head;
	while (buf)
	{
		buf->selection = 0;
		down_key_handler(global);
		buf = buf->next;
	}
}

void	return_key_handler(t_global *global)
{
	restore_terminal(global);
	print_selection(global->head);
	exit(0);
}

void	left_key_handler(t_global *global)
{
	t_input *end; /* implement a func for end */
	t_colors colors;

	init_color_data(&colors);
	colors.data = global->current->data;
	end = global->current;
	while (end->next)
		end = end->next;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
			global->current->x, global->current->y), INPUT_FD);
	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0, global);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0, global);
	}
	if (global->current->prev == NULL)
		global->current = end;
	else
		global->current = global->current->prev;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL),
		global->current->x, global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
}

void	delete_key_handler(t_global *global)
{
	delete_node(&global->head, global->current, global->longest, global);
	right_key_handler(global);
}
