/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:12:07 by ybachar           #+#    #+#             */
/*   Updated: 2022/11/10 11:19:49 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putun(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 9 && n >= 0)
		count += ft_putchar(n + 48);
	else if (n < 0)
	{
		count += ft_putchar('-');
		n *= -1;
		count += ft_putun(n);
	}
	else
	{
		count += ft_putun(n / 10);
		count += ft_putun(n % 10);
	}
	return (count);
}
