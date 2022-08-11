/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 00:59:51 by jgarcia           #+#    #+#             */
/*   Updated: 2022/06/02 02:36:09 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(const char *str)
{
	int	printed;

	printed = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	if (*str == '\0')
		return (0);
	while (*str)
	{
		printed += write(1, str, 1);
		str ++;
	}
	return (printed);
}
