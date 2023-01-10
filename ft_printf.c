/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iecharak <iecharak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:04:48 by iecharak          #+#    #+#             */
/*   Updated: 2022/11/08 15:06:22 by iecharak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_format(va_list p, char c)
{
	if (c == 'c')
		return (ft_putchar_l(va_arg(p, int)));
	if (c == 's')
		return (ft_putstr_l(va_arg(p, char *)));
	if (c == 'p')
		return (ft_hdp_d_l(va_arg(p, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_l(va_arg(p, int)));
	if (c == 'u')
		return (ft_put_unbr_l(va_arg(p, unsigned int)));
	if (c == 'x' || c == 'X')
		return (ft_hd_d_l(va_arg(p, unsigned int), c));
	if (c == '%')
		return (ft_putchar_l('\%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	p;
	int		l;
	int		i;
	int		persent;

	l = 0;
	i = 0;
	persent = 0;
	va_start(p, s);
	while (s[i])
	{
		if (s[i] != '%')
			l += ft_putchar_l(s[i]);
		else if (s[i++] == '%')
			persent = 1;
		if (persent && s[i])
		{
			l += check_format(p, s[i]);
			persent = 0;
		}
		i++;
	}
	va_end(p);
	return (l);
}

int	ft_hd_d_l(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (n > 15)
	{
		i += ft_hd_d_l(n / 16, c);
		i += ft_hd_d_l(n % 16, c);
	}
	else if (n >= 0 && n < 10)
	{
		i += (ft_putchar_l(n + '0'));
	}
	else if (n > 9 && n < 16)
	{
		if (c == 'X')
			i += (ft_putchar_l(n + 55));
		if (c == 'x')
			i += (ft_putchar_l(n + 87));
	}
	return (i);
}

static int	ft_ptr_l(unsigned long n)
{
	int	i;

	i = 0;
	if (n > 15)
	{
		i += ft_ptr_l(n / 16);
		i += ft_ptr_l(n % 16);
	}
	else if (n >= 0 && n < 10)
	{
		i += (ft_putchar_l(n + '0'));
	}
	else if (n > 9 && n < 16)
	{
		i += (ft_putchar_l(n + 7 + '0' + 32));
	}
	return (i);
}

int	ft_hdp_d_l(unsigned long n)
{
	int	i;

	i = ft_putstr_l("0x");
	i += ft_ptr_l(n);
	return (i);
}
int	ft_put_unbr_l(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 9)
	{
		i += ft_putchar_l(n + '0');
	}
	else
	{
		i += ft_putnbr_l(n / 10);
		i += ft_putnbr_l(n % 10);
	}
	return (i);
}
// int	ft_put_unbr_l(unsigned int n)
// {
// 	int	i;

// 	i = 0;
// 	if (n <= 9)
// 	{
// 		i += ft_putchar_l(n + '0');
// 	}
// 	else
// 	{
// 		i += ft_putnbr_l(n / 10);
// 		i += ft_putnbr_l(n % 10);
// 	}
// 	return (i);
// }
int	ft_putchar_l(char c)
{
	write(1, &c, 1);
	return (1);
}

// int	ft_putnbr_l(int n)
// {
// 	int	i;

// 	i = 0;
// 	if (n == -2147483648)
// 	{
// 		write(1, "-2147483648", 11);
// 		return (11);
// 	}
// 	else if (n < 0)
// 	{
// 		n *= -1;
// 		i += ft_putchar_l('-');
// 		i += ft_putnbr_l(n);
// 	}
// 	else if (n <= 9)
// 	{
// 		i += ft_putchar_l(n + '0');
// 	}
// 	else
// 	{
// 		i += ft_putnbr_l(n / 10);
// 		i += ft_putnbr_l(n % 10);
// 	}
// 	return (i);
// }

int	ft_putnbr_l(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		n *= -1;
		i += ft_putchar_l('-');
		i += ft_putnbr_l(n);
	}
	else if (n <= 9)
	{
		i += ft_putchar_l(n + '0');
	}
	else
	{
		i += ft_putnbr_l(n / 10);
		i += ft_putnbr_l(n % 10);
	}
	return (i);
}

int	ft_putstr_l(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_l("(null)"));
	while (s[i])
	{
		ft_putchar_l(s[i]);
		i++;
	}
	return (i);
}