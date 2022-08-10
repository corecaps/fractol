/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_escape.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 23:47:22 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/09 23:58:23 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*******************************************************************************
 * calculate for the point p the number of iteration before the functions      *
 * tend to infinity.                                                           *
 * @return the number of iteration or 0 if the function remains stable for     *
 * point p                                                                     *
 ******************************************************************************/

static int	calc_escape(t_data *data, t_complex p)
{
	int			iter;
	long double	tmp;
	t_complex	c;

	iter = 0;
	c = p;
	while (((p.r * p.r) + (p.i * p.i) < 4.0L) && (iter < data->max_iter))
	{
		tmp = ((p.r * p.r) - (p.i * p.i)) + c.r;
		p.i = fabsl(2.0L * p.r * p.i) + c.i;
		p.r = tmp;
		iter ++;
	}
	if (iter == data->max_iter)
		return (0);
	else if (iter <=5)
		return (5);
	return (iter);
}

/*******************************************************************************
 * go through every point in the image and calculate the value                 *
 * if point is in the burning escape set pixel is set to black                 *
 * if point is not in the set color in function of the iteration it took to    *
 * determine point is not in set                                               *
 ******************************************************************************/

void	burning_escape(t_data *data)
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
			color = calc_escape(data, warp_coord_to_complex(x, y, data));
//			color = (int)round(pow(color, 0.5) * 0xff
//					/ pow(data->max_iter, 0.5));
//			color = color * 0x10000;
			color = hsv_to_rgb(0,
									   100,
									   (int) round((pow(color,0.5) * 100)
												   / pow(data->max_iter,0.5)),data->color_offset);
			put_pixel_2_img(data->img_buffer, x, y, color);
		}
	}
}