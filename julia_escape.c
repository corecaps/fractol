/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_algorithm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:44:13 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/27 12:44:17 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void julia_escape(t_data *data)
{
	static t_complex	c = {.i = 0,.r = -2};
	t_complex 	point;
	long double	tmp;
	int 		x;
	int 		y;
	int 		iter;
	int 		color;
	c.r += 0.01;
	if (c.r >= 1.0)
	{
		c.r = -2.0;
		c.i += 0.2;
	}
	data->redraw = 1;
	y = 0;
	while (y < data->size_y -1)
	{
		x = 0;
		while (x < data->size_x -1 )
		{
			point = warp_coord_to_complex(x,y,data);
			iter = 0;
            while ((point.r * point.r + point.i * point.i <= 4) && (iter < data->max_iter))
                {
                    tmp = point.r * point.r - point.i * point.i + c.r;
                    point.i = 2 * point.r * point.i + c.i;
                    point.r = tmp;
                    iter++;
                }
			if (iter <= 2)
				iter = 2;
			if (iter == data->max_iter)
				iter = 0;
			if (iter > 0)
				color = hsv_to_rgb((iter * 360 )/ data->max_iter,100,(log(iter) * 100)/ log(data->max_iter));
			else
				color = 0;
			put_pixel_2_img(data->img_buffer,x,y,color);
			x ++;
		}
		y ++;
	}
}