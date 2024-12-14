/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 18:00:46 by ybenchel          #+#    #+#             */
/*   Updated: 2024/11/14 10:07:33 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			count;

	if (!format || write (1, 0, 0) == -1)
		return (-1);
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_handle_percent(format, args);
		}
		else
		{
			count += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

// int main()
// {
//     int ret_ft = 0, ret_orig = 0;

//     // Single character
//     ret_ft = ft_printf("ft_printf: Single character: %c\n", 'A');
//     ret_orig = printf("printf: Single character: %c\n", 'A');
//     ret_orig = printf("original return : %d | mine return : %d",
	// ret_orig, ret_orig);
//     return 0;
// }