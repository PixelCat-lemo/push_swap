/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:58:44 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 16:44:30 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rrotate(t_stack **stack)
{
	t_stack		*temp;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	while (temp->next->next)
		temp = temp->next;
	temp->next->next = *stack;
	*stack = temp->next;
	temp->next = NULL;
	return (1);
}

void	rra(t_data *data)
{
	rrotate(&data->a);
}

void	rrb(t_data *data)
{
	rrotate(&data->b);
}

void	rrr(t_data *data)
{
	rrotate(&data->a);
	rrotate(&data->b);
}
