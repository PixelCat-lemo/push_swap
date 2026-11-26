/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:28:12 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/26 17:55:38 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_stack	*temp;

	if (!data->a || !data->a->next)
		return ;
	temp = data->a;
	data->a = data->a->next;
	temp->next = data->a->next;
	data->a->next = temp;
}

void	sb(t_data *data)
{
	t_stack	*temp;

	if (!data->b || !data->b->next)
		return ;
	temp = data->b;
	data->b = data->b->next;
	temp->next = data->b->next;
	data->b->next = temp;
}

void	ss(t_data *data)
{
	t_stack	*temp;

	if (data->a && data->a->next)
	{
		temp = data->a;
		data->a = data->a->next;
		temp->next = data->a->next;
		data->a->next = temp;
	}
	if (data->b && data->b->next)
	{
		temp = data->b;
		data->b = data->b->next;
		temp->next = data->b->next;
		data->b->next = temp;
	}
}