/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_selection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:54:46 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/12 16:13:45 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static const int	keys[KEY_ARRAY_SIZE] =
{
	ESC, UP, DOWN, RIGHT, LEFT, RETURN,
	SPACE, BACK_SPACE, DEL,
	CTRL_A, CTRL_W
};

static const t_events ke[KEY_ARRAY_SIZE] =
	{
		esc_key_handler, up_key_handler, down_key_handler, 
		esc_key_handler, esc_key_handler, esc_key_handler, 
		esc_key_handler, esc_key_handler, esc_key_handler, 
		esc_key_handler, esc_key_handler
};

void	key_selection(int key, t_global *input)
{
	int i;

	i = 0;
	while (i < KEY_ARRAY_SIZE)
	{
		if (keys[i] == key)
		{
			ke[i](input);
			break ;
		}
		i++;
	}
}
