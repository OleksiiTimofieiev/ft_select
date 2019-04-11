/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:31:17 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 20:15:37 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termcap.h>
# include <termios.h>

# include "../libft/libft.h"

# define SPACES	4

/*
************************ ADT for data **********************************
*/

typedef struct		s_input
{
	char			*data;
	int				x;
	int				y;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

t_input				*g_pointer;

/*
************************ termcap settings **********************************
*/

typedef struct		s_termcap_cmd
{
	char			*cl; /* window */
	char			*cm; /* cursor */
	char			*vi; /* String of commands to make the cursor invisible */
	char			*ve; /* String of commands to return the cursor to normal */
}					t_termcap_cmd;

/*
************************* initialization routines *************************
*/

void				init_data(int argc, char **argv, t_input **input, int *len);
void				init_termcap(t_termcap_cmd *tc_cmd);
void				init_terminal(char *termtype);
void				init_coordinates(t_input **input, int len);
void				set_coordinates(t_input *input, int word_per_line, int len);

/*
************************* data modifications *************************
*/

void				delete_node(t_input **head_ref, t_input *del, int len);
void				add_node(t_input **head_ref, char *data);

/*
************************* output *************************
*/

void				print_to_terminal(t_input *input);

/*
************************* error func *************************
*/

void				print_error(char *error_type);

#endif
