/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumiguel <lumiguel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:34:22 by lumiguel          #+#    #+#             */
/*   Updated: 2023/11/27 18:25:12 by lumiguel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <unistd.h>

# define LOWERBASE "0123456789abcdef"
# define UPPERBASE "0123456789ABCDEF"

int		ft_printf16(unsigned long long n, char *base);
int		ft_printnbr(long int n);
int		ft_putnbr_u(unsigned int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);
int		ft_printf_agrs(const char *str, unsigned long long i, va_list ptr);
int		ft_printf(const char *str, ...);

#endif