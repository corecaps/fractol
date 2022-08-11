/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:15:39 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/02 02:49:05 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	print_arg(char t, va_list args)
{
	int	buf;

	if (t == '%')
		return (write(1, "%", 1));
	else if (t == 'c')
	{
		buf = (unsigned char) va_arg(args, int);
		return (write(1, &buf, 1));
	}
	else if (t == 's')
		return (print_str(va_arg(args, char *)));
	else if (t == 'd' || t == 'i')
		return (print_n(va_arg(args, int)));
	else if (t == 'p')
		return (print_p(va_arg(args, void *)));
	else if (t == 'u')
		return (print_un(va_arg(args, unsigned int)));
	else if (t == 'x')
		return (print_hex(va_arg(args, unsigned int), FT_CASE_LOW));
	else if (t == 'X')
		return (print_hex(va_arg(args, unsigned int), FT_CASE_UP));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		printed;
	int		buf;

	printed = 0;
	va_start(args, str);
	if (!str || str[0] == '\0')
		return (0);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '\0')
		{
			str ++;
			buf = print_arg(*str, args);
			if (buf >= 0)
				printed += buf;
			else
				return (-1);
		}
		else
			printed += write(1, str, 1);
		str ++;
	}
	va_end(args);
	return (printed);
}
