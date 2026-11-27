/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:34:47 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 17:40:20 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack		*temp;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = *stack;
	*stack = (*stack)->next;
	temp = temp->next;
	temp->next = NULL;
	return (1);
}

void	ra(t_data *data)
{
	rotate(&data->a);
}

void	rb(t_data *data)
{
	rotate(&data->b);
}

void	rr(t_data *data)
{
	rotate(&data->a);
	rotate(&data->b);
}
