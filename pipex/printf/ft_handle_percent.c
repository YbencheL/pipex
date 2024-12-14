/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:32:37 by ybenchel          #+#    #+#             */
/*   Updated: 2024/11/13 12:07:35 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_int(va_list args, char specifier)
{
	int				count;
	int				n;
	unsigned int	u;

	count = 0;
	if (specifier == 'd' || specifier == 'i')
	{
		n = va_arg(args, int);
		ft_putnbr(n);
		count += ft_intlen(n);
	}
	else if (specifier == 'u')
	{
		u = va_arg(args, unsigned int);
		ft_putnbr_unsigned(u);
		count += ft_intlen_base(u, 10);
	}
	return (count);
}

static int	handle_hex(va_list args, char specifier)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	return (ft_puthexo(x, specifier == 'X'));
}

static int	handle_str_char(va_list args, char specifier)
{
	int		count;
	char	*s;
	char	c;

	count = 0;
	if (specifier == 's')
	{
		s = va_arg(args, char *);
		if (s == NULL)
			s = "(null)";
		while (*s)
		{
			count += ft_putchar(*s);
			s++;
		}
	}
	else if (specifier == 'c')
	{
		c = (char)va_arg(args, int);
		count += ft_putchar(c);
	}
	return (count);
}

static int	handle_ptr(va_list args)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(args, void *);
	return (ft_putptr(ptr));
}

int	ft_handle_percent(const char *format, va_list args)
{
	int	count;

	count = 0;
	if (*format == '%')
	{
		ft_putchar('%');
		count++;
	}
	else if (*format == 'd' || *format == 'i' || *format == 'u')
		count += handle_int(args, *format);
	else if (*format == 'x' || *format == 'X')
		count += handle_hex(args, *format);
	else if (*format == 's' || *format == 'c')
		count += handle_str_char(args, *format);
	else if (*format == 'p')
		count += handle_ptr(args);
	return (count);
}
