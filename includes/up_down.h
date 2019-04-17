/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_down.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:18:55 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:29:44 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UP_DOWN_H
# define UP_DOWN_H

# include "t_input_struct.h"

int		quantity_words(t_input *input);
t_input	*last_row_start(int words_per_line, int quantity_of_words);
t_input	*last_row_start_not(int words_per_line, int quantity_of_words);
void	null_the_pointers(t_input *input);
t_input *get_end_ptr(t_input *input);

#endif
