/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 13:49:16 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/22 10:49:02 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_print_point(unsigned long n, const char *base, int *cp)
{
	if (n >= 16)
		ft_print_point(n / 16, base, cp);
	ft_putchar(base[n % 16], cp);
}
