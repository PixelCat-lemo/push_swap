/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-lemo <pde-lemo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:46:18 by pde-lemo          #+#    #+#             */
/*   Updated: 2026/11/20 12:22:11 by pde-lemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa(unsigned long n, char type)
{
	char	*base;
	int		count;

	base = NULL;
	count = 0;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else if (type == 'x')
		base = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hexa(n / 16, type);
	ft_putchar_fd(base[n % 16], 1);
	return (count + 1);
}

int	ft_putptr(void *ptr)
{
	unsigned long	count;

	if (!ptr)
		return (ft_putstr_len("(nil)"));
	count = 0;
	count += ft_putstr_len("0x");
	count += ft_putnbr_hexa((unsigned long)ptr, 'x');
	return (count);
}

int	ft_putstr_len(char *s)
{
	int	len;

	if (!s)
		return (ft_putstr_len("(null)"));
	len = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (len);
}

static unsigned int	ft_len(unsigned int num)
{
	unsigned int	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		len++;
		num /= 10;
	}
	return (len);
}

char	*ft_itoa_unsigned(unsigned int n)
{
	char			*str;
	unsigned int	len;

	len = ft_len(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n /= 10;
	}
	return (str);
}
