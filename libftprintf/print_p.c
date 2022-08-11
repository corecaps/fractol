/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 02:44:28 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/02 03:03:40 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_ptr_size(unsigned long long int n)
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

static void	ft_ptoa(unsigned long long int n, char *result, size_t index)
{
	if (n > 15)
		ft_ptoa(n / 16, result, index - 1);
	if (n % 16 > 9)
		result[index] = n % 16 - 9 + FT_CASE_LOW;
	else
		result[index] = n % 16 + '0';
}

int	print_p(void *ptr)
{
	unsigned long long	intptr;
	char				*result;
	size_t				size;
	int					printed;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	size = 0;
	intptr = (unsigned long long int) ptr;
	size += ft_ptr_size(intptr);
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (-1);
	ft_ptoa(intptr, result, size - 1);
	result[size] = '\0';
	printed = write(1, "0x", 2);
	printed += write(1, result, size);
	free (result);
	return (printed);
}
