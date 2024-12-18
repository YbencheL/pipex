/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:29:19 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/14 11:26:25 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	if (size == 0)
		return (ft_strlen(src));
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	i = 0;
	if (d_len >= size)
		return (size + s_len);
	while (src[i] != '\0' && (d_len + i) < (size - 1))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
}

// #include <string.h>
// int main()
// {
// 	char dest[10];
// 	printf("%lu\n", strlcat(dest, "apah", 0));
// }
