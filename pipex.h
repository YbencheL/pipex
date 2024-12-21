/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenchel <ybenchel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:45:41 by ybenchel          #+#    #+#             */
/*   Updated: 2024/12/21 17:22:52 by ybenchel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

char	**ft_split(char const *s, char c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	execute_command(char *cmd, int input_f, int output_f, char **env);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
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
