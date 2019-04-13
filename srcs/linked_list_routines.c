/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_routines.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:43:47 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 21:11:57 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	delete_node(t_input **head_ref, t_input *del, int len, t_global *global)
{
	int word_per_line;

	if (*head_ref == NULL || del == NULL)
		esc_key_handler(global);
	if (*head_ref == del)
	{
		global->head = del->next;
		*head_ref = del->next;
	}
	if (del->next != NULL)
		del->next->prev = del->prev;
	if (del->prev != NULL)
		del->prev->next = del->next;
	free(del->data);
	free(del);

	// char *cl = tgetstr("cl", NULL);
	word_per_line = tgetnum("co") / (len + SPACES);
	set_coordinates(*head_ref, word_per_line, len);
	// ft_putstr_fd(cl, INPUT_FD); // clear window
	print_to_terminal(*head_ref);
}

void	add_node(t_input **head_ref, char *data)
{
    // /* 1. allocate node */
    // t_input* new_node = (t_input*)malloc(sizeof(t_input)); 
  
    // t_input* last = *head_ref; /* used in step 5*/
  
    // /* 2. put in the data  */
    // new_node->data = ft_strdup(data);
	// new_node->x = 0;
	// new_node->y = 0;
	// new_node->selection = 0; 
  
    // /* 3. This new node is going to be the last node, so 
    //       make next of it as NULL*/
    // new_node->next = NULL; 
    
  
    // /* 4. If the Linked List is empty, then make the new 
    //       node as head */
    // if (*head_ref == NULL) { 
    //     new_node->prev = NULL; 
    //     *head_ref = new_node; 
    //     return; 
    // } 
  
    // /* 5. Else traverse till the last node */
    // while (last->next != NULL) 
    //     last = last->next; 
  
    // /* 6. Change the next of last node */
    // last->next = new_node; 
  
    // /* 7. Make last node as previous of new node */
    // new_node->prev = last;

	// void push(struct Node * *head_ref, int new_data)
	// {
		/* 1. allocate node */
		t_input *new_node = (t_input *)malloc(sizeof(t_input));

		/* 2. put in the data  */
		new_node->data = ft_strdup(data);
		new_node->x = 0;
		new_node->y = 0;
		new_node->selection = 0;

		/* 3. Make next of new node as head and previous as NULL */
		new_node->next = (*head_ref);
		new_node->prev = NULL;

		/* 4. change prev of head node to new node */
		if ((*head_ref) != NULL)
			(*head_ref)->prev = new_node;

		/* 5. move the head to point to the new node */
		(*head_ref) = new_node;
	// }
}
