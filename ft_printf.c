/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:33:57 by yowoo             #+#    #+#             */
/*   Updated: 2023/11/01 10:47:38 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arglist;
	int		cnt;

	va_start(arglist, format);
	cnt = 0;
	if (*format == 0 || format == 0)
		return (0);
	while (*format != '\0')
	{
		if (*format != '%')
			ft_printf_c(*format);
		else
		{
			format++;
			if ((*format >= 9 && *format <= 13) || *format == 32)
				ft_putstr(va_arg(arglist, char *));
			else if (*format == 'c')
				ft_printf_c(va_arg(arglist, int));
			else if (*format == 's')
				cnt = cnt + ft_printf_s(va_arg(arglist, char *)) - 1;
			else if (*format == 'p')
				cnt = cnt + ft_printf_p(va_arg(arglist, unsigned long)) - 1;
			else if (*format == 'd' || *format == 'i')
				cnt = cnt + ft_printf_int(va_arg(arglist, int)) - 1;
			else if (*format == 'u')
				cnt = cnt + ft_printf_u(va_arg(arglist, unsigned int)) - 1;
			else if (*format == 'x' || *format == 'X')
				cnt = cnt + ft_printf_x(va_arg(arglist, int), format) - 1 ;
			else if (*format == '%')
				ft_printf_c('%');
		}
		format++;
		cnt++;
	}
	va_end(arglist);
	return (cnt);
}

// prefix vs postfix => str++ vs ++str
// va_list arglist; == //have all the arguments in ...(ellipsis)
// va_start( arguments, format); 
// to initialize the list "argument", you need va_start;

// int	main(void)
// {
// 	int	res1;

// 	res1 = ft_printf(" mypf: %X ", -1);
// 	printf("\n pf: %X ", -1);
// 	printf("\nreturnmy:%d",res1);
// 	return (0);
// }
