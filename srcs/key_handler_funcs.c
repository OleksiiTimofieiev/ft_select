/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:32:11 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:54:57 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"



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
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);

	int quantity_of_words = quantity_words_local(global->head);
	int words_per_line = w.ws_col / (global->longest + SPACES);

	// ft_putstr_fd(ft_itoa(quantity_of_words), 0);
	// ft_putstr_fd("->", 0);

	// ft_putstr_fd(ft_itoa(words_per_line), 0);

	if (quantity_of_words <= words_per_line)
	{
		right_key_handler(global);
		return ;
	}


	int i;
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
	if (global->current->next == NULL && !global->current->pointer_down)
	{
			// ft_putstr_fd("********************",0);
		global->current = global->head;
	}
	else
	{
		i = global->words_per_line;
		int null_detected = 0;
		t_input *buf = global->current;
		while (i--)
		{
			if (global->current->next == NULL)
			{
				null_detected = 1;
				break;
			}
			global->current = global->current->next;
		}
		if (null_detected)
		{

			if (buf->pointer_down)
				global->current = buf->pointer_down;
			else
				global->current = global->head;
				
		}
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
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);

	int quantity_of_words = quantity_words_local(global->head);
	int words_per_line = w.ws_col / (global->longest + SPACES);

	// ft_putstr_fd(ft_itoa(quantity_of_words), 0);
	// ft_putstr_fd("->", 0);

	// ft_putstr_fd(ft_itoa(words_per_line), 0);

	if (quantity_of_words <= words_per_line)
	{
		left_key_handler(global);
		return;
	}

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
	if (null_detected && buf->pointer_up)
		global->current = buf->pointer_up;
		else if (null_detected)
		{
			global->current = end;
		}
		
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
	end = global->current; // use end func;
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
	t_colors colors;

	init_color_data(&colors);
	colors.data = global->current->data;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					   global->current->y),
				 INPUT_FD);
	if (global->current->selection == 0)
		ft_putstr_fd_select(&colors, 0, global);
	else
	{
		colors.color1 = BACK;
		ft_putstr_fd_select(&colors, 0, global);
	}
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					   global->current->y), INPUT_FD);
	colors.color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd_select(&colors, 0, global);
	change_of_longest(g_evil.head);
	init_up_down(&g_evil);
}
