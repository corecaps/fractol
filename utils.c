/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 00:44:20 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 00:45:06 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*******************************************************************************
 * map pixel coordinate to complex point coordinates                           *
 ******************************************************************************/

t_complex	warp_coord_to_complex(int x, int y, t_data *data)
{
	t_complex	point;

	point.r = data->start_r
			  + ((long double)(x * (data->stop_r - data->start_r)))
				/ data->size_x;
	point.i = data->start_i
			  + ((long double)(y * (data->stop_i - data->start_i)))
				/ data->size_y;
	return (point);
}

/*******************************************************************************
 * ft_itoa util function to determine size of the string to be allocated       *
 * @param n number to convert                                                  *
 * @return size of the string                                                  *
 ******************************************************************************/

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
/*******************************************************************************
 * ft_itoa utils function
 * convert a base 10 int  to corresponding ascii string                        *
 * @param n int to convert                                                     *
 * @param buf pointer to a heap allocated string of size + 1                   *
 ******************************************************************************/
static void	ft_dectoascii(long int n, char *buf, size_t index)
{
	if (n > 9)
		ft_dectoascii(n / 10, buf, index - 1);
	buf[index] = (n % 10) + '0';
}

/*******************************************************************************
 * convert an int to a string                                                  *
 * @param n number to convert into string                                      *
 * @return a pointer to the string (heap allocated)                            *
 ******************************************************************************/

char	*ft_itoa(int n)
{
	long long int	abs_n;
	char			*result;
	size_t			size;

	size = 0;
	abs_n = (long) n;
	if (n < 0)
	{
		abs_n *= -1;
		size ++;
	}
	size += ft_int_dec_size(abs_n);
	result = malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	ft_dectoascii(abs_n, result, size - 1);
	if (n < 0)
		result[0] = '-';
	result[size] = '\0';
	return (result);
}