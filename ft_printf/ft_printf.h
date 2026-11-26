/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 10:41:56 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/19 18:27:37 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_putnbr_hexa(unsigned long n, char type);
int		ft_putptr(void *s);
int		ft_putstr_len(char *s);
char	*ft_itoa_unsigned(unsigned int n);

#endif