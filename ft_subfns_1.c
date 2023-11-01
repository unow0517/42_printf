/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subfns_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 09:57:55 by yowoo             #+#    #+#             */
/*   Updated: 2023/11/01 10:04:52 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n)
{
	int	output;

	if (n == -2147483648)
	{
		write(1, "-2", 2);
		write(1, "147483648", 9);
	}
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n < 10 && n >= 0)
	{
		output = n + 48;
		write(1, &output, 1);
	}
}

size_t	ft_strlen(const char *str)
{
	unsigned int	len;

	len = 0;
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_putstr(char *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}


