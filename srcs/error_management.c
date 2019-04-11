/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 20:00:25 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 21:03:09 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	print_error(char *error_type)
{
	ft_printf("%s\n", error_type);
	ft_printf("Process will be terminated.\n");
	exit(0);
}