/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algorithms.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 14:19:52 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 17:40:20 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Simple: Bubble sort adaptation
// Medium: Chunk-based sorting
// Complex: LSD Radix Sort

#include "push_swap.h"

int	choose_algorithm(t_data *data)
{
	if (data->algorithm == SIMPLE)
		simplealgorithm(data);
	if (data->algorithm == MEDIUM)
		mediumalgorithm(data);
	if (data->algorithm == COMPLEX)
		complexalgorithm(data);
	if (data->algorithm == ADAPTIVE)
	{
		if (data->disorder < 0.2)
			simplealgorithm(data);
		if (data->disorder >= 0.2 && data->disorder < 0.5)
			mediumalgorithm(data);
		if (data->disorder >= 0.5)
			complexalgorithm(data);
	}
	return (0);
}

t_data	simplealgorithm(t_data *data)
{
	int	total;
	int	loop1;
	int	loop2;

	total = ft_lstsize(data->a);
	loop1 = 0;
	while (loop1 < total - 1)
	{
		loop2 = 0;
		while (loop2 < total - loop1 - 1)
		{
			if (data->a->value > data->a->next->value)
				sa(data->a);
			ra(data->a);
			loop2++;
		}
		rra(data->a);
		loop1++;
	}
}

t_data	mediumalgorithm(t_data *data)
{
	
}

t_data	complexalgorithm(t_data *data)
{
	
}
