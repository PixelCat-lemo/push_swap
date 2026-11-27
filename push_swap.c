/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:45:02 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 17:40:21 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// validate arguments
// calculate indexes
// calculate disorder
// choose algorithm
// O(n2)
// O(n√n)
// O(n log n)
// sort stack A
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc <= 1)
		return (0);
	data = init_data();
	if (!data)
		return (1);
	if (!parse_input(argc, argv, data))
	{
		ft_lstclear(&data->a, free);
		write(2, "Error\n", 6);
		return (1);
	}
	disordercalc(data->a);
	choose_algorithm(data);
	print_benchmark(data, data->disorder);
	return (ft_lstclear(data, free), 0);
}

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = NULL;
	data->b = NULL;
	data->bench = 0;
	data->disorder = 0.0;
	data->algorithm = ADAPTIVE;
	return (data);
}

float	disordercalc(t_stack *a)
{
	int		disorder;
	int		total;
	t_stack	*temp;
	t_stack	*temp_comp;

	disorder = 0;
	total = 0;
	temp = a;
	temp_comp = a->next;
	while (temp_comp)
	{
		while (temp_comp)
		{
			if (temp->value > temp_comp->value)
				disorder++;
			temp_comp = temp_comp->next;
			total++;
		}
		temp = temp->next;
		temp_comp = temp->next;
	}
	return ((float)disorder / (float)total);
}
