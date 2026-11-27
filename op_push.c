/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 14:20:45 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 17:40:21 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **src, t_stack **dst)
{
	t_stack		*temp;

	if (!*src)
		return (0);
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
	return (1);
}

void	pa(t_data *data)
{
	push(&data->b, &data->a);
}

void	pb(t_data *data)
{
	push(&data->a, &data->b);
}
