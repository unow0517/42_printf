/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yowoo <yowoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 10:34:14 by yowoo             #+#    #+#             */
/*   Updated: 2023/11/01 10:47:16 by yowoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int		ft_printf(const char *format, ...);

//functions
void	ft_printf_c(char c);
int		ft_printf_s(char *s);
int		ft_printf_p(unsigned long ptr);
int		ft_printf_int(int n);
int		ft_printf_u(unsigned int num);
int		ft_printf_x(unsigned int n, const char *format);


//subfns_1
void	ft_putnbr(int n);
size_t	ft_strlen(const char *str);
void	ft_putstr(char *s);

//subfns_2
int		hex_len_u(unsigned long n);
int		dec_len_uint(unsigned int n);
void	ft_put_hex_u(unsigned long n);
void	ft_put_hexbig_u(unsigned long n);


//here clean it out again 









