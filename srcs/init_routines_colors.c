/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_routines_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:35:50 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 18:36:05 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void sl_set_default_color(t_input *arg)
{
	arg->color_type = EMPTY_COLOR;
	arg->color = EMPTY_COLOR;
}

void initial_select(t_global *global, int len)
{
	t_colors colors;

	init_color_data(&colors);
	colors.color2 = UNDERLINED;
	colors.color3 = ITALIC;
	colors.data = global->current->data;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
					   global->current->y),
				 OUTPUT_FD);

	ft_putstr_fd_select(&colors, 0, global);

	global->words_per_line = tgetnum("co") / (len + SPACES);
}

void init_color(t_input *input)
{
	struct stat sb;

	while (input)
	{
		if (lstat(input->data, &sb) == 0)
		{
			if (S_ISLNK(sb.st_mode))
			{
				input->color_type = EMPTY_COLOR;
				input->color = MAGENTA;
			}
			else if (S_ISDIR(sb.st_mode))
			{
				input->color_type = BOLD;
				input->color = CYAN;
			}
			else if (sb.st_mode & S_IXUSR)
			{
				input->color_type = EMPTY_COLOR;
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
