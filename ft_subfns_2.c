/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subfns_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 10:00:19 by yowoo             #+#    #+#             */
/*   Updated: 2023/11/01 10:47:05 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len_u(unsigned long n)
{
	int	len;

	len = 0;
	while (n >= 16)
	{
		len++;
		n = n / 16;
	}
	return (len + 1);
}

int	dec_len_uint(unsigned int n)
{
	if (n >= 1000000000)
		return (10);
	if (n >= 100000000)
		return (9);
	if (n >= 10000000)
		return (8);
	if (n >= 1000000)
		return (7);
	if (n >= 100000)
		return (6);
	if (n >= 10000)
		return (5);
	if (n >= 1000)
		return (4);
	if (n >= 100)
		return (3);
	if (n >= 10)
		return (2);
	return (1);
}

void	ft_put_hex_u(unsigned long n)
{
	if (n >= 16)
	{
		ft_put_hex_u(n / 16);
		ft_put_hex_u(n % 16);
	}
	else if (n <= 9)
	{
		ft_printf_c(n + '0');
	}
	else
	{
		ft_printf_c(n - 10 + 'a');
	}
}

void	ft_put_hexbig_u(unsigned long n)
{
	if (n >= 16)
	{
		ft_put_hexbig_u(n / 16);
		ft_put_hexbig_u(n % 16);
	}
	else if (n <= 9)
	{
		ft_printf_c(n + '0');
	}
	else
	{
		ft_printf_c(n - 10 + 'A');
	}
}
