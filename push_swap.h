/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:58:30 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/26 15:06:35 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include "ft_printf/ft_printf.h"
# define MAX_SIZE 100

typedef struct s_stack
{
	int	content[MAX_SIZE];
	int	*top;
}	t_stack;

#endif