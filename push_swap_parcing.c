/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parcing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 11:21:14 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 17:40:21 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_input(int argc, char **argv, t_data *data)
{
	int	index;
	int	algorithm_selected;

	index = 1;
	algorithm_selected = 0;
	while (index < argc)
	{
		if (parse_algorithm(argv[index], data))
		{
			if (algorithm_selected)
				return (0);
			algorithm_selected = 1;
		}
		else if (!parce_arguments(argv[index], data))
			return (0);
		index++;
	}
	return (1);
}

static int	parse_algorithm(char *arg, t_data *data)
{
	if (ft_strcmp(arg, "--simple") == 0)
		data->algorithm = SIMPLE;
	else if (ft_strcmp(arg, "--medium") == 0)
		data->algorithm = MEDIUM;
	else if (ft_strcmp(arg, "--complex") == 0)
		data->algorithm = COMPLEX;
	else if (ft_strcmp(arg, "--adaptive") == 0)
		data->algorithm = ADAPTIVE;
	else
		return (0);
	return (1);
}

static int	parce_arguments(char *arg, t_data *data)
{
	char	**arr;
	int		index;
	int		value;
	t_stack	*new_node;

	arr = ft_split(arg, ' ');
	if (!arr || !arr[0])
		return (free_split(arr), 0);
	index = 0;
	while (arr[index])
	{
		if (!is_valid_int(arr[index], &value) || has_duplicate(data->a, value))
			return (free_split(arr), 0);
		new_node = ft_lstnew(value);
		if (!new_node)
			return (free_split(arr), 0);
		ft_lstadd_back(&data->a, new_node);
		index++;
	}
	return (free_split(arr), 1);
}

static int	is_valid_int(char *s, int *out)
{
	long	numbr;
	int		sign;
	int		index;

	numbr = 0;
	sign = 1;
	index = 0;
	if (s[index] == '-' || s[index] == '+')
	{
		if (s[index] == '-')
			sign = -1;
		index++;
	}
	if (!ft_isdigit(s[index]))
		return (0);
	while (ft_isdigit(s[index]))
	{
		numbr = numbr * 10 + (s[index++] - '0');
		if (numbr > (long)INT_MAX + (sign == -1))
			return (0);
	}
	if (s[index])
		return (0);
	*out = (int)(numbr * sign);
	return (1);
}

static int	has_duplicate(t_data *data, int value)
{
	while (data->a)
	{
		if (data->a->value == value)
			return (1);
		data->a = data->a->next;
	}
	return (0);
}
