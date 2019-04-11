/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otimofie <otimofie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 14:45:27 by otimofie          #+#    #+#             */
/*   Updated: 2019/04/11 14:57:36 by otimofie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		init_data(int argc, char **argv, t_input **input)
{
	int	max;
	int len;

	max = 0;
	len = 0;
	while (argc != 0)
	{
		add_node(input, argv[argc]);
		len = ft_strlen(argv[argc]);
		if (len > max)
			max = len;
		argc--;
	}
	return (max);
}
