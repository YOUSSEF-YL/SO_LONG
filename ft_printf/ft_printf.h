/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybachar <ybachar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:35:18 by ybachar           #+#    #+#             */
/*   Updated: 2022/11/09 15:02:35 by ybachar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int			ft_printf(const char *mode, ...);
int			ft_putnbr(long n);
int			ft_putchar(int c);
int			ft_putstr(char *str);
int			ft_puthex(unsigned int n, char *base);
int			ft_puthexp(unsigned long n, char *base);
int			ft_putun(unsigned int n);
#endif