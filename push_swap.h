/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:58:30 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/26 17:28:03 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	struct s_stack	*a;
	struct s_stack	*b;
	int             bench;          // yes or no
    float           disorder;       // mistakes / total pairs
}	t_data;

void    sa(t_data *data);

void    sb(t_data *data);

void    ss(t_data *data);

#endif