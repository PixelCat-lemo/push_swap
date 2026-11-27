/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bench.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 16:16:08 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 17:40:20 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	decimal_disorder(float num, int fd)
{
	int	percentage;
	int	integer;
	int	decimal;

	percentage = (int)(num * 10000);
	integer = percentage / 100;
	decimal = percentage % 100;
	ft_printf("[bench] disorder: %i.", integer);
	if (decimal < 10)
		ft_printf("0");
	ft_printf("%i%%\n", decimal);
	return (0);
}

int	printstratagy(t_data *data)
{
	if (data->algorithm == SIMPLE)
		ft_printf("[bench] strategy: SIMPLE / O(n2)\n");
	else if (data->algorithm == MEDIUM)
		ft_printf("[bench] strategy: MEDIUM / O(n√n)\n");
	else if (data->algorithm == COMPLEX)
		ft_printf("[bench] strategy: COMPLEX / O(n log n)\n");
	else if (data->algorithm == ADAPTIVE)
	{
		if (data->disorder < 0.2)
			ft_printf("[bench] strategy: ADAPTIVE / %s\n", "O(n2)");
		if (data->disorder >= 0.2 && data->disorder < 0.5)
			ft_printf("[bench] strategy: ADAPTIVE / %s\n", "O(n√n)");
		if (data->disorder >= 0.5)
			ft_printf("[bench] strategy: ADAPTIVE / %s\n", "O(n log n)");
	}
}

// int	oprationtotal()
// {
// 	ft_printf("[bench] total\n");
// }
