/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:31:17 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 16:47:42 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termcap.h>
# include <termios.h>	

# include "../libft/libft.h"

# define SPACES	4

typedef struct		s_input
{
	char			*data;
	int				x;
	int				y;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

int					init_data(int argc, char **argv, t_input **input);
void				delete_node(t_input **head_ref, t_input *del, int len);
void				add_node(t_input **head_ref, char *data);
void set_coordinates(t_input *input, int word_per_line, int len);

#endif
