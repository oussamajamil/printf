/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:45:28 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/20 13:53:36 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
void ft_putchar(int c, int *cp);
void ft_case_of_ft_printf(va_list argc, int *cp, int i, const char *str);
int ft_printf(const char *str, ...);
void ft_putstr(char *str, int *cp);
void ft_putnbr(int n, int *cp);
void ft_putnbr_unsigned(unsigned int n, int *cp);
void ft_print_hexa(unsigned int, const char *base, int *cp);
void ft_print_point(unsigned int n, const char *base, int *cp);
#endif