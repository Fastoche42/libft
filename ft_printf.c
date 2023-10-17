/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:23:07 by fl-hote           #+#    #+#             */
/*   Updated: 2022/04/16 17:05:27 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_printstr(char *str)
{
	int	i;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr(unsigned int p, int *ptrlen)
{
	if (p > 9)
		ft_putnbr(p / 10, ptrlen);
	*ptrlen += ft_putchar(p % 10 + '0');
}

int	ft_printnbr(int n)
{
	unsigned int	p;
	int				len;

	len = 0;
	if (n < 0)
		len = ft_putchar('-');
	p = ((2 * (n > 0) - 1) * n);
	ft_putnbr(p, &len);
	return (len);
}

int	ft_formats(va_list pt_arg, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(pt_arg, int)));
	else if (format == 's')
		return (ft_printstr(va_arg(pt_arg, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_printnbr(va_arg(pt_arg, int)));
	else if (format == 'p')
		return (ft_printptr(va_arg(pt_arg, unsigned long long)));
	else if (format == 'u')
		return (ft_print_uint(va_arg(pt_arg, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(pt_arg, unsigned int), format));
	else if (format == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	pt_arg;
	int		print_lg;

	i = 0;
	print_lg = 0;
	va_start(pt_arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_lg += ft_formats(pt_arg, str[i + 1]);
			i++;
		}
		else
			print_lg += ft_putchar(str[i]);
		i++;
	}
	va_end(pt_arg);
	return (print_lg);
}
