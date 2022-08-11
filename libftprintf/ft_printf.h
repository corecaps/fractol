/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:39:35 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/02 02:49:30 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define FT_CASE_UP 64
# define FT_CASE_LOW 96

int	print_str(const char *str);
int	print_n(long long int n);
int	print_p(void *ptr);
int	print_un(unsigned long int n);
int	print_hex(int n, int wcase);
int	ft_printf(const char *str, ...);

#endif
