/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:42:19 by ybachar           #+#    #+#             */
/*   Updated: 2022/11/09 15:01:19 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexp(unsigned long n, char *base)
{
	int	count;

	count = 0;
	if (n >= 0 && n < 16)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_puthexp(n / 16, base);
		count += ft_puthexp(n % 16, base);
	}
	return (count);
}
