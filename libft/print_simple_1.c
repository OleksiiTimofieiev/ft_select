/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_simple_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:53:45 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/12 18:56:29 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printer_simple_string(int *spaces, int *chars, char p)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (g_v.k & F_M)
	{
		while (i++ < *chars)
			g_v.quantity += write(1, &g_v.t.str[j++], 1);
		while (i++ <= g_v.mfw)
			g_v.quantity += write(1, &p, 1);
	}
	else
	{
		while (i++ < *spaces)
			g_v.quantity += write(1, &p, 1);
		while (i++ <= g_v.mfw && g_v.t.str[j])
			g_v.quantity += write(1, &g_v.t.str[j++], 1);
	}
}
