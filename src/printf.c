/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojamil <ojamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 11:36:06 by ojamil            #+#    #+#             */
/*   Updated: 2021/11/19 12:21:10 by ojamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar(int c, int *cp)
{
	write(1, &c, 1);
	*cp = *cp + 1;
}

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

void ft_putnbr_unsigned(unsigned int n, int *cp)
{
    if (n >= 0 && n < 10)
        ft_putchar(n + '0', cp);
    else
    {
        ft_putnbr(n / 10, cp);
        ft_putchar((n % 10) + '0', cp);
    }
}

void ft_putstr(char *str, int *cp)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i], cp);
		i++;
	}
}

void ft_print_hexa(long long int n, const char *base, int *cp)
{
	if (base[1] == 'x')
	{
		ft_putstr("0x", cp);
		base = base + 2;
	}
	if (n <= 16)
		ft_putchar(base[n], cp);
	else
	{
		ft_print_hexa(n / 16, base, cp);
		ft_putchar(base[n % 16], cp);
	}
}

int ft_printf(const char *str, ...)
{
	va_list argc;
	int i;
	int cp;

	i = 0;
	cp = 0;
	va_start(argc, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i], &cp);
		else
		{
			i++;
			if (str[i] == 's')
				ft_putstr(va_arg(argc, char *), &cp);
			if (str[i] == 'c')
				ft_putchar(va_arg(argc, int), &cp);
			if (str[i] == '%')
				ft_putchar('%', &cp);
			if (str[i] == 'a')
				ft_print_hexa(va_arg(argc, int), "0123456789ABCDEF", &cp);
			if (str[i] == 'x')
				ft_print_hexa(va_arg(argc, unsigned int), "0123456789abcdef", &cp);
			if (str[i] == 'i' || str[i] == 'd')
				ft_putnbr(va_arg(argc, int), &cp);
			if (str[i] == 'p')
				ft_print_hexa(va_arg(argc, long long int), "0x0123456789abcdef", &cp);
			if (str[i] == 'u')
				ft_putnbr_unsigned(va_arg(argc,int),&cp);
		}
		i++;
	}
	return (cp);
}
int main()
{
	int cp;

	cp = 0;
	char *cp1 = "";

	//ft_printf("oussama %c %s age : %d en hexa maj %a  en hexa min %x ",'-',"oussama",0x12,10,10);
	/*printf("%u\n",1000);
	ft_printf("%u\n",1000);
	printf("%u\n",0);
    ft_printf("%u\n",0);
	printf("%u\n",-100);
    ft_printf("%u\n",-100);
	printf("%u\n",-35055);
    ft_printf("%u\n",-35055);*/
	printf ("%s");
	//ft_prinf("%sdddd %d", NULL,NULL);
	return (0);
}
