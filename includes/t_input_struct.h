/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_input_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:26:52 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:29:59 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_INPUT_STRUCT_H
# define T_INPUT_STRUCT_H

/*
************************ ADT for data **********************************
*/

typedef struct			s_input
{
	char				*data;
	int					x;
	int					y;
	int					selection;
	int					row_detect;
	char				*color;
	char				*color_type;
	struct s_input		*pointer_up;
	struct s_input		*pointer_down;
	struct s_input		*next;
	struct s_input		*prev;
}						t_input;

#endif
