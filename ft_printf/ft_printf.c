/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:54:28 by ybachar           #+#    #+#             */
/*   Updated: 2023/01/10 13:17:49 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_putchar(int c)
{
	int	count;

	count = 1;
	write(1, &c, 1);
	return (count);
}

int	switshcase(int count, va_list args, const char *mode, int i)
{
	
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
#include <limits.h>
#include <stdio.h>
int main()
{
	ft_printf("test");
	//ft_printf(" %s %s \n","*","-");

	//printf("%s\n",NULL );
	//printf(" %s %s \n","*","-");
}
