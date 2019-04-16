/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_routines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:43:47 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/16 19:55:42 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_node(t_input **head_ref, t_input *del, int len, t_global *global)
{
	int				word_per_line;
	struct winsize	w;

	if (del->next == NULL)
		global->current = global->head;
	else
		global->current = del->next;
	if (*head_ref == NULL || del == NULL)
		esc_key_handler(global);
	if (*head_ref == del)
	{
		global->head = del->next;
		global->input = del->next;
		*head_ref = del->next;
	}
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del->data);
	free(del);
	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	word_per_line = w.ws_col / (len + SPACES);
	set_coordinates(*head_ref, word_per_line, len);
	print_to_terminal(*head_ref);
}

void	add_node(t_input **head_ref, char *data)
{
	t_input *new_node;

	new_node = (t_input *)malloc(sizeof(t_input));
	new_node->data = ft_strdup(data);
	new_node->x = 0;
	new_node->y = 0;
	new_node->selection = 0;
	new_node->next = (*head_ref);
	new_node->prev = NULL;
	new_node->pointer_up = NULL;
	new_node->pointer_down = NULL;
	new_node->color = EMPTY_COLOR;
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;
	(*head_ref) = new_node;
}
