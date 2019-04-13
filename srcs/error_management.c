/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:00:25 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/13 17:45:45 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_error(char *error_type)
{
	ft_putstr_fd(error_type, 0);
	ft_putstr_fd("\nProcess will be terminated.\n", 0);
	exit(0);
}
