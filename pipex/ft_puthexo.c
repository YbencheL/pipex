/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:09:01 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/15 17:41:44 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_puthexo(unsigned long n, int upper)
{
	char	*base;
	int		count;

	count = 0;
	if (upper == 1)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		count += ft_puthexo(n / 16, upper);
		count += ft_putchar(base[n % 16]);
	}
	else
		count += ft_putchar(base[n]);
	return (count);
}
