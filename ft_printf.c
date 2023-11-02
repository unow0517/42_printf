/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:33:57 by yowoo             #+#    #+#             */
/*   Updated: 2023/11/02 15:54:49 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arglist;
	int		cnt;
	int		temp;

	va_start(arglist, format);
	cnt = 0;
	if (*format == 0 || format == 0)
		return (0);
	while (*format != '\0')
	{
		if (*format != '%')
		{
			temp = ft_printf_c(*format);
			// printf("temp:%d",temp);
		}
		else
		{
			temp = ft_specifiers(++format,arglist);
			// printf("tempd:%d",temp);
		}
		if (temp == -1)
		{
			va_end(arglist);
			return (-1);
		}
		format++;
		cnt += temp;
	}
	// printf("inspec: %d",cnt);
	va_end(arglist);
	return (cnt);
}


// int	main(void)
// {
// 	int	res1;
// 	int	res;

// 	res1 = ft_printf("%d", -10);
// 	printf("%c",'\n');
// 	res = printf("%d", -10);
// 	printf("\nreturnmy:%d",res1);
// 	printf("\nreturn:%d",res);

// 	return (0);
// }
