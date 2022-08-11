/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 17:54:25 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/02 02:07:50 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_int_hex_size(long int n)
{
	int	size;

	size = 1;
	while (n > 15)
	{
		n /= 16;
		size ++;
	}
	return (size);
}

static void	ft_htoa(long int n, char *result, size_t index, int wcase)
{
	if (n > 15)
		ft_htoa(n / 16, result, index - 1, wcase);
	if (n % 16 > 9)
		result[index] = n % 16 - 9 + wcase;
	else
		result[index] = n % 16 + '0';
}

int	print_hex(unsigned int n, int wcase)
{
	long	abs_n;
	char	*result;
	size_t	size;
	int		printed;

	size = 0;
	abs_n = (unsigned long) n;
	size += ft_int_hex_size(abs_n);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (-1);
	ft_htoa(abs_n, result, size - 1, wcase);
	result[size] = '\0';
	printed = write(1, result, size);
	free (result);
	return (printed);
}
