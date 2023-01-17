/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:54:28 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/17 11:01:37 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	switshcase(int count, va_list args, const char *mode, int i)
{
	if (mode[i] == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (mode[i] == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (mode[i] == 'p')
	{
		count += ft_putstr("0x");
		count += ft_puthexp(va_arg(args, unsigned long), "0123456789abcdef");
	}
	else if (mode[i] == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (mode[i] == 'i')
		count += ft_putnbr(va_arg(args, int));
	else if (mode[i] == 'u')
		count += ft_putun(va_arg(args, unsigned int));
	else if (mode[i] == 'x')
		count += ft_puthex(va_arg(args, int), "0123456789abcdef");
	else if (mode[i] == 'X')
		count += ft_puthex(va_arg(args, int), "0123456789ABCDEF");
	else if (mode[i] == '%')
		count += ft_putchar(mode[i]);
	else
		count += ft_putchar(mode[i]);
	return (count);
}

int	ft_printf(const char *mode, ...)
{
	int		count;
	va_list	args;
	int		i;

	i = 0;
	count = 0;
	va_start(args, mode);
	while (mode[i] != '\0')
	{
		if (mode[i] == '%')
		{
			i++;
			count = switshcase(count, args, mode, i);
		}
		else
			count += ft_putchar(mode[i]);
		i++;
	}
	va_end(args);
	return (count);
}
