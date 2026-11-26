/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:45:02 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/26 17:50:14 by pde-lemo         ###   ########.fr       */
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
	float	disorder;

	data = NULL;
	if (argc <= 1)
		return (write(1, "Not enough inputs\n", 19), 1);
	data = parce_arguments(argc, argv);
	if (!data)
		return (1);
	disorder = disordercalc(data);
	printf("Index of disorder (inversions): %d\n", disorder);
	if (disorder < 0.2)
	{
		
	}
	if (0.2 <= disorder < 0.5)
	{
		
	}
}

t_data	*parce_arguments(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = NULL;
	data->b = NULL;
	data->bench = 0;
	data->disorder = 0.0;
	if (argc == 2)
	{
		its_string(argv, data);
		return (free_data(data), NULL);
	}
	else if (argc > 2)
	{
		its_digit(argc, argv, data);
		return (free_data(data), NULL);
	}
	return (data);
}

t_data	*its_string(char **argv, t_data	*data)
{
	int		stringindex;
	char	**arr;
	t_data	*new_node;

	arr = ft_split(argv[1], ' ');
	if (!arr)
		return ;
	stringindex = 0;
	while (arr[stringindex])
	{
		new_node = ft_lstnew(ft_atoi(arr[stringindex]));
		if (!new_node)
			return ;
		ft_lstadd_back(&data->a, new_node);
		free(arr[stringindex]);
		stringindex++;
	}
	free(arr);
}

t_data	*its_digit(int argc, char **argv, t_data	*data)
{
	int		stringindex;
	t_data	*new_node;

	stringindex = 1;
	while (stringindex < argc)
	{
		new_node = ft_lstnew(ft_atoi(argv[stringindex]));
		if (!new_node)
			return ;
		ft_lstadd_back(&data->a, new_node);
		stringindex++;
	}
}

float	disordercalc(t_stack *a) // arg is data->a
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
			total++;
			temp_comp = temp_comp->next;
		}
		temp = temp->next;
		temp_comp = temp->next;
	}
	return (disorder / total);
}
