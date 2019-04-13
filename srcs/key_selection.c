/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_selection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:46 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 18:16:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static const int64_t keys[KEY_ARRAY_SIZE] =
	{
		ESC, UP, DOWN, RIGHT, LEFT, RETURN,
		SPACE, BACK_SPACE, DEL,
		CTRL_A, CTRL_W};

static const t_events funcs[KEY_ARRAY_SIZE] =
{
	esc_key_handler, up_key_handler, down_key_handler,
	right_key_handler, left_key_handler, return_key_handler,
	space_key_handler, delete_key_handler, delete_key_handler,
	select_all_handler, deselect_all_handler
};

void key_selection(int key, t_global *input)
{
	int i;

	i = -1;
	// ft_putstr_fd("1\n", 0);

	while (++i < KEY_ARRAY_SIZE)
	{
		if (keys[i] == key)
		{
			// ft_putstr_fd("2\n", 0);

			funcs[i](input);
			break ;
		}
	}
}
