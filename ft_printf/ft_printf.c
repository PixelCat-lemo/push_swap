/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:34:34 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/26 11:21:57 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conversion(const char type, va_list *vargs)
{
	char	*str;
	int		count;

	count = 0;
	if (type == 'c')
		return (ft_putchar_fd(va_arg(*vargs, int), 1), 1);
	else if (type == 'u')
		str = ft_itoa_unsigned(va_arg(*vargs, unsigned int));
	else if (type == 'i' || type == 'd')
		str = ft_itoa(va_arg(*vargs, int));
	else if (type == 's')
		return (ft_putstr_len(va_arg(*vargs, char *)));
	else if (type == 'x' || type == 'X')
		return (ft_putnbr_hexa(va_arg(*vargs, unsigned int), type));
	else if (type == 'p')
		return (ft_putptr(va_arg(*vargs, void *)));
	else if (type == '%')
		return (ft_putchar_fd('%', 1), 1);
	else
		return (-1);
	if (!str)
		return (-1);
	count = ft_putstr_len(str);
	free(str);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	vargs;

	count = 0;
	i = 0;
	if (!str)
		return (-1);
	va_start (vargs, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] && ft_strchr("cspdiuxX%", str[i + 1]))
			count += ft_conversion(str[++i], &vargs);
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end (vargs);
	return (count);
}
