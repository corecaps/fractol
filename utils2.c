/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:33:11 by jgarcia           #+#    #+#             */
/*   Updated: 2022/05/23 14:13:36 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <limits.h>
/*
double atof(const char *s)
{
	// This function stolen from either Rolf Neugebauer or Andrew Tolmach.
	// Probably Rolf.
	double a = 0.0;
	int e = 0;
	int c;
	while ((c = *s++) != '\0' && isdigit(c)) {
		a = a*10.0 + (c - '0');
	}
	if (c == '.') {
		while ((c = *s++) != '\0' && isdigit(c)) {
			a = a*10.0 + (c - '0');
			e = e-1;
		}
	}
	if (c == 'e' || c == 'E') {
		int sign = 1;
		int i = 0;
		c = *s++;
		if (c == '+')
			c = *s++;
		else if (c == '-') {
			c = *s++;
			sign = -1;
		}
		while (isdigit(c)) {
			i = i*10 + (c - '0');
			c = *s++;
		}
		e += i*sign;
	}
	while (e > 0) {
		a *= 10.0;
		e--;
	}
	while (e < 0) {
		a *= 0.1;
		e++;
	}
	return a;
} */

static char	*ft_remove_space(const char *str)
{
	size_t	pos;

	pos = 0;
	while ((str[pos] != '\0') && ((str[pos] == ' ')
			|| ((str[pos] >= 9) && (str[pos] <= 13))))
		pos ++;
	return ((char *)str + pos);
}

static long int	check_result(long int result, int signe)
{
	if (result > INT_MAX || result < INT_MIN)
	{
		if (signe < 1)
			return (0);
		else
			return (-1);
	}
	return (result);
}
static int     ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
		return (2048);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int			signe;
	size_t		pos;
	long int	result;

	signe = 1;
	result = 0;
	nptr = ft_remove_space(nptr);
	if (nptr[0] == '-')
	{
		signe *= -1;
		nptr ++;
	}
	else if (nptr[0] == '+')
		nptr ++;
	pos = 0;
	while (nptr[pos] != '\0')
	{
		if (!(ft_isdigit(nptr[pos])))
			return (0);
		result = result * 10 + nptr[pos] - '0';
		pos ++;
	}
	result *= signe;
	result = check_result(result, signe);
	return (result);
}