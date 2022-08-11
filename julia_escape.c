/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_escape.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:44:13 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/11 15:05:39 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/******************************************************************************
 * iterate julia function until it escape to infinity for point p             *
 * using point data->julia->c                                                 *
 * @return number of iteration it took for function to break stability        *
 *****************************************************************************/
static int	calc_escape(t_data *data, t_complex c, t_complex p)
{
	long double	tmp;
	int			iter;

	iter = 0;
	while ((p.r * p.r + p.i * p.i <= 4) && (iter < data->max_iter))
	{
		tmp = p.r * p.r - p.i * p.i + c.r;
		p.i = 2 * p.r * p.i + c.i;
		p.r = tmp;
		iter ++;
	}
	return (iter);
}

/******************************************************************************
 * map each pixel to a point in the complex point determined by simulation    *
 * parameters in data structure and check if the point is in julia set        *
 *****************************************************************************/

void	julia_escape(t_data *data)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y ++ < data->size_y - 1)
	{
		x = 0;
		while (x ++ < data->size_x - 1)
		{
			color = calc_escape(data, data->julia_c,
					warp_coord_to_complex(x, y, data));
			put_pixel_2_img(data->img_buffer, x, y, get_color(data, color));
		}
	}
}
