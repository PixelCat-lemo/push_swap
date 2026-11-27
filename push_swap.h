/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 13:58:30 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/27 17:40:21 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <limits.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef enum e_algorithm // struct with all algorithms as - pde-lemo
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_algorithm;

typedef struct s_data
{
	struct s_stack		*a;
	struct s_stack		*b;
	t_algorithm			algorithm;		// needed to add this so I could store if the flag (--complex/etc) was used - pde-lemo
	int					bench;          // yes or no
    double         		disorder;       // mistakes / total pairs
}	t_data;

void		sa(t_data *data);	// swap first 2 elements of stack a

void		sb(t_data *data);	// swap first 2 elements of stack b

void		ss(t_data *data);	// sa and sb simultaneously

void		pa(t_data *data);	// push first element of stakc b to stack a

void		pb(t_data *data);	// push first element of stack a to stack b

void		ra(t_data *data);	// shift up stack a elements

void		rb(t_data *data);	// shift up stack b elements

void		rr(t_data *data);	// ra and rb simultaneously

void		rra(t_data *data);	// shift down stack a elements

void		rrb(t_data *data);	// shift down stack b elements

void		rrr(t_data *data);	// rra and rrb simultaneously

/*=====================push_swap_parcing.c=========================*/
static int	parce_arguments(char *arg, t_data *data);/* 
Split an argument into individual numbers, validate them, 
and add them to stack A. */

static int	is_valid_int(char *s, int *out);/* 
Check whether a string represents a valid integer within the int range.*/

int			parse_input(int argc, char **argv, t_data *data);/*
Process every argument passed to the program.*/

static int	parse_algorithm(char *arg, t_data *data);/*
*/

/*===========================push_swap.c============================*/
float		disordercalc(t_stack *a);/* 
*/

#endif