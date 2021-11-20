/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:21:02 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/20 13:52:01 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void ft_case_of_ft_printf(va_list argc, int *cp, int i, const char *str)
{
	i++;
	if (str[i] == 's')
		ft_putstr(va_arg(argc, char *), cp);
	if (str[i] == 'c')
		ft_putchar(va_arg(argc, int), cp);
	if (str[i] == '%')
		ft_putchar('%', cp);
	if (str[i] == 'X')
		ft_print_hexa(va_arg(argc, unsigned int), "0123456789ABCDEF", cp);
	if (str[i] == 'x')
		ft_print_hexa(va_arg(argc, unsigned int), "0123456789abcdef", cp);
	if (str[i] == 'i' || str[i] == 'd')
		ft_putnbr(va_arg(argc, int), cp);
	if (str[i] == 'p')
		ft_print_point(va_arg(argc, unsigned int), "0123456789abcdef", cp);
	if (str[i] == 'u')
		ft_putnbr_unsigned(va_arg(argc, int), cp);
}

int ft_printf(const char *str, ...)
{
	int i;
	int cp;

	i = 0;
	cp = 0;
	va_list argc;
	va_start(argc, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &cp);
		else
		{
			ft_case_of_ft_printf(argc, &cp, i, str);
			i++;
		}
		i++;
	}
	va_end(argc);
	return (cp);
}
