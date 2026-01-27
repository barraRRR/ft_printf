/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbarreir <jbarreir@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 17:44:36 by jbarreir          #+#    #+#             */
/*   Updated: 2026/01/27 21:39:13 by jbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// *********** INCLUDES ************
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// ************ DEFINES ************

// ********* DATA STRUCTS **********


// ********** PROTOTYPES ***********
int		ft_printf(char const *str, ...);
ssize_t	printf_putunbr(unsigned int n);
ssize_t	printf_putptr(unsigned long ptr);
ssize_t	printf_puthex(unsigned long long n, char const *hex);
ssize_t	printf_putnbr(int n);
ssize_t	printf_putstr(char *s);
ssize_t	printf_putchr(char c);
ssize_t	arg_parser(va_list *ap, char arg);
int		is_arg(char c2);
ssize_t	ft_strlen(const char *str);

#endif
