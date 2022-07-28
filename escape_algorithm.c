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

t_complex warp_coord_to_complex(int x, int y, t_data *data)
{
	t_complex point;

	point.r = data->start_r + ((double) (x) * (data->stop_r - data->start_r)) / data->size_x;
	point.i = data->start_i + ((double) (y) * (data->stop_i - data->start_i)) / data->size_y;
	return (point);
}

void render_escape(t_data *data)
{
	t_complex	c;
	t_complex 	point;
	double		tmp;
	int 		x;
	int 		y;
	int 		iter;

	y = 0;
	while (y < data->size_y -1)
	{
		x = 0;
		while (x < data->size_y -1 )
		{
			c = warp_coord_to_complex(x,y,data);
			point = c;
			iter = 0;
			while ((point.r * point.r + point.i * point.i <= 2) && (iter < MAX_ITER))
			{
				tmp = point.r * point.r - point.i * point.i + c.r;
				point.i = 2 * point.r * point.i + c.i;
				point.r = tmp;
				iter ++;
			}
			if (iter == MAX_ITER)
				iter = 0;
			iter = iter * 255 / MAX_ITER;
			put_pixel_2_img(data->img_buffer,x,y,iter);
			x ++;
		}
		y ++;
	}
}