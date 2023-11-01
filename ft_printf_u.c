/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 07:46:48 by yowoo             #+#    #+#             */
/*   Updated: 2023/11/01 10:25:57 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*putintplus(unsigned int num)
{
	char	*res;
	int		len;
	int		j;

	j = 0;
	len = dec_len_uint(num);
	// printf("len: %d",len);
	res = (char *)malloc((len + 1) * sizeof(char));

	if (!res)
		return (0);
	while (j < len)
	{
		res[len - j - 1] = (num % 10) + 48;
		num = num / 10;
		j++;
	}
	res[len] = '\0';
	return (res);
}

int	ft_printf_u(unsigned int num)
{
	int		res;
	char	*ptr;

	if (num == 0)
	{
		ft_putnbr(0);
		return (1);
	}
	else
	{
		ptr = putintplus(num);
		ft_putstr(ptr);
		free(ptr);
	}
	res = dec_len_uint(num);
	return (res);
}

//ft_putnbr ==> range is small for unsigned int