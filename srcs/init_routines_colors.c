/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routines_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:35:50 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/16 19:49:59 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	sl_set_default_color(t_input *arg)
{
	arg->color_type = EMPTY_COLOR;
	arg->color = EMPTY_COLOR;
}

void		initial_select(t_global *global, int len)
{
	t_colors		colors;
	struct winsize	w;

	init_color_data(&colors);
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
		global->current->y), INPUT_FD);
	ft_putstr_fd_select(&colors, 0, global);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	global->words_per_line = w.ws_col / (len + SPACES);
}

void		init_color(t_input *input)
{
	struct stat	sb;

	while (input)
	{
		if (lstat(input->data, &sb) == 0)
		{
			if (S_ISLNK(sb.st_mode))
				input->color = MAGENTA;
			else if (S_ISDIR(sb.st_mode))
			{
				input->color_type = BOLD;
				input->color = CYAN;
			}
			else if (sb.st_mode & S_IXUSR)
			{
				input->color = RED;
			}
			else
				sl_set_default_color(input);
		}
		else
			sl_set_default_color(input);
		input = input->next;
	}
}

void		init_terminal_state(t_global *g_evil, t_input *input, int len)
{
	g_evil->head = input;
	g_evil->current = input;
	g_evil->input = input;
	tcgetattr(INPUT_FD, &g_evil->initial_terminal_state);
	tcgetattr(INPUT_FD, &g_evil->new_terminal_state);
	g_evil->new_terminal_state.c_lflag &= ~(ICANON | ECHO);
	g_evil->new_terminal_state.c_cc[VMIN] = 1;
	g_evil->new_terminal_state.c_cc[VTIME] = 0;
	tcsetattr(INPUT_FD, TCSANOW, &g_evil->new_terminal_state);
	init_termcap(&g_evil->terminal_state);
	tputs(tgetstr("ti", NULL), 1, print_key);
	tputs(tgetstr("vi", NULL), 1, print_key);
	g_evil->longest = len;
}
