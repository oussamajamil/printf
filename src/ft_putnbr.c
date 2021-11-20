/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 09:20:03 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/20 10:00:37 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void ft_putnbr(int n, int *cp)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*cp = *cp + 11;
		return;
	}
	else if (n < 0)
	{
		ft_putchar('-', cp);
		n *= -1;
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + '0', cp);
	else
	{
		ft_putnbr(n / 10, cp);
		ft_putchar((n % 10) + '0', cp);
	}
}