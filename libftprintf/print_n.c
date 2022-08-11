/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:46:19 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/02 03:09:16 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_int_dec_size(long int n)
{
	int	size;

	size = 1;
	while (n > 9)
	{
		n /= 10;
		size ++;
	}
	return (size);
}

static void	ft_dectoascii(long int n, char *buf, size_t index)
{
	if (n > 9)
		ft_dectoascii(n / 10, buf, index - 1);
	buf[index] = (n % 10) + '0';
}

int	print_n(long long int n)
{
	long long int	abs_n;
	char			*result;
	size_t			size;
	int				printed;

	size = 0;
	abs_n = n;
	if (n < 0)
	{
		abs_n *= -1;
		size ++;
	}
	size += ft_int_dec_size(abs_n);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (-1);
	ft_dectoascii(abs_n, result, size - 1);
	if (n < 0)
		result[0] = '-';
	result[size] = '\0';
	printed = write(1, result, size);
	free(result);
	return (printed);
}
