/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:31:17 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 18:48:32 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termcap.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/xattr.h>

# include "../libft/libft.h"
# include "keys.h"

# define SPACES	4
# define OUTPUT_FD 0
# define INPUT_FD 1

/*
************************ ADT for data **********************************
*/

typedef struct			s_input
{
	char				*data;
	int					x;
	int					y;
	int					selection;
	char				*color;
	char				*color_type;
	struct s_input		*next;
	struct s_input		*prev;
}						t_input;

/*
************************ termcap settings **********************************
*/

typedef struct			s_termcap_cmd
{
	char				*cl;
	char				*cm;
	char				*vi;
	char				*ve;
	char				*ti;
	char				*te;
}						t_termcap_cmd;

typedef struct			s_colors
{
	char				*color1;
	char				*color2;
	char				*color3;
	char				*color4;
	char				*data;
}						t_colors;

typedef	struct			s_global
{
	t_input				*head;
	t_input				*current;
	t_input				*end;
	int					words_per_line;
	struct termios		initial_terminal_state;
	struct termios		new_terminal_state;
	t_termcap_cmd		terminal_state;
	int					longest;
}						t_global;

/*
************************* array of function pointers *************************
*/

typedef	void			(*t_events)(t_global *current);

/*
************************* initialization routines *************************
*/

void					init_data(int argc, char **argv,
						t_input **input, int *len);
void					init_termcap(t_termcap_cmd *tc_cmd);
void					init_terminal(char *termtype);
void					init_coordinates(t_input **input, int len);
void					set_coordinates(t_input *input,
						int word_per_line, int len);
void					init_color(t_input *input);
void initial_select(t_global *global, int len);
void init_terminal_state(t_global *g_evil, t_input *input, int len);

	/*
************************* data modifications *************************
*/

	void delete_node(t_input **head_ref, t_input *del,
					 int len, t_global *global);
void					add_node(t_input **head_ref, char *data);

/*
************************* output *************************
*/

void					print_to_terminal(t_input *input);
void					print_selection(t_input *input);
void					restore_terminal(t_global *global);

/*
************************* error func *************************
*/

void					print_error(char *error_type);
void					esc_key_handler(t_global *input);
void					down_key_handler(t_global *global);
void					up_key_handler(t_global *global);
void					space_key_handler(t_global *global);
void					select_all_handler(t_global *global);
void					deselect_all_handler(t_global *global);
void					return_key_handler(t_global *global);
void					key_selection(int key, t_global *input);
void					left_key_handler(t_global *globa);
void					right_key_handler(t_global *global);
void					delete_key_handler(t_global *global);
void					init_color_data(t_colors *colors);
void					ft_putstr_fd_select(t_colors *colors,
							int fd, t_global *global);
void main_loop(void);
	t_global g_evil;

#endif
