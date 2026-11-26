/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:45:02 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/26 16:01:59 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parce_arguments(argc, **argv);
	if (argc <= 1)
		write(1, "Not enough inputs\n", 19);
	if (argv == "--simple")
		ft_printf("use simple");
	else if (argv == "--medium")
		ft_printf("use medium");
	else if (argv == "--complex")
		ft_printf("use complex");
	else
		ft_printf("use adaptive");
}

t_stack	*parce_arguments(int argc, char **argv)
{
	int		index;
	int		loop;
	char	*arr;
	t_stack	*stack_a;

	index = 1;
	loop = 0;
	if (argc == 2 && argv[index])
	{
		arr = ft_split(argv[1], ' ');
		while (argv[1][loop] != '\0')
		{
			ft_lstadd_back(stack_a, arr[loop]);
			loop++;
		}
	}
	if (argc > 2)
	{
		while (argv[index++] != argc)
		{
			ft_lstadd_back(stack_a, argv[index]);
		}
	}
}
