/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:53:18 by ybenchel          #+#    #+#             */
/*   Updated: 2024/11/13 10:24:15 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
int		ft_intlen(int n);
int		ft_putchar(char c);
void	ft_putnbr(int n);
int		ft_puthexo(unsigned long n, int upper);
int		ft_putstr(char *s);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_intlen_base(unsigned int n, int base);
int		ft_putptr(unsigned long addr);
int		ft_handle_percent(const char *format, va_list args);

#endif