/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 09:50:31 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/15 17:41:54 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_putptr(unsigned long addr)
{
	int	count;

	count = 0;
	if (addr == 0)
		return (ft_putstr("0x0"));
	count += ft_putstr("0x");
	count += ft_puthexo(addr, 0);
	return (count);
}
