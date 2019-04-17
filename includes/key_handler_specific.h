/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_specific.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:56:06 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/17 16:57:12 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HANDLER_SPECIFIC
# define KEY_HANDLER_SPECIFIC

# include "t_input_struct.h"

int		quantity_words_local(t_input *input);
void	change_of_longest(t_input *input);

#endif