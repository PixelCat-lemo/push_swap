/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:28:12 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 16:50:29 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack		*temp;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (1);
}

void	sa(t_data *data)
{
	swap(&data->a);
}

void	sb(t_data *data)
{
	swap(&data->b);
}

void	ss(t_data *data)
{
	swap(&data->a);
	swap(&data->b);
}
