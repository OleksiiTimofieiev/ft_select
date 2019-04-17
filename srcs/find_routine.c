/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_routine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 12:32:47 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 12:35:28 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	print_find(t_colors *colors, t_global *global)
{
	colors->data = global->current->data;
	colors->color1 = (global->current->selection) ? BACK : EMPTY_COLOR;
	colors->color2 = UNDERLINED;
	colors->color3 = ITALIC;
	ft_putstr_fd(tgoto(tgetstr("cm", NULL), global->current->x,
				global->current->y), INPUT_FD);
	ft_putstr_fd_select(colors, INPUT_FD, global);
}

static void	find_the_word(t_global *global, char *read_str)
{
	t_input		*buf;
	t_colors	colors;

	buf = global->head;
	while (buf)
	{
		if (ft_strstr(buf->data, read_str))
		{
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
			global->current = buf;
			print_find(&colors, global);
			break ;
		}
		buf = buf->next;
	}
}

void		find_routine(t_global *global, char c)
{
	char	read_str[256];
	int		key;
	int		i;

	key = 0;
	i = 0;
	ft_memset(read_str, '\0', sizeof(read_str));
	read_str[i++] = c;
	while (i < 256)
	{
		read(INPUT_FD, &key, 8);
		if (!ft_isalpha(key) || key == RETURN)
			break ;
		read_str[i++] = key;
	}
	find_the_word(global, read_str);
}
