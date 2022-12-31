/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:55:27 by ybachar           #+#    #+#             */
/*   Updated: 2022/11/09 15:01:01 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char *base)
{
	int	count;

	count = 0;
	if (n >= 0 && n < 16)
		count += ft_putchar(base[n]);
	else
	{
		count += ft_puthex(n / 16, base);
		count += ft_puthex(n % 16, base);
	}
	return (count);
}
