/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 12:31:17 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 14:47:10 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libft/libft.h"

# include <stdlib.h>
# include <termcap.h>

# include <termios.h>

typedef struct		s_input
{
	char			*data;
	struct s_input	*next;
	struct s_input	*prev;
}					t_input;

void				init_data(int argc, char **argv, t_input **input);
void				delete_node(t_input **head_ref, t_input *del);
void				add_node(t_input **head_ref, char *data);

#endif
