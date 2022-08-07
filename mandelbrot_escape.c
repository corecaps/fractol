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

static int get_color(const t_data *data, int iter)
{
	int color;
	if (iter <= 3)
		iter = 3;
	if (iter == data->max_iter)
		iter = 0;
	if (iter > 0) // TODO implement color animation with static offset to hue
		color = hsv_to_rgb((iter * 360 )/ data->max_iter,100,(int)round((log(iter) * 100)/ log(data->max_iter)));
	else
		color = 0;
	return color;
}

static int calc_escape_value(const t_data *data, t_complex c, int iter)
{
	long double	tmp;
	t_complex p = c;
	while ((p.r * p.r + p.i * p.i <= 2) && (iter < data->max_iter))
	{
		tmp = p.r * p.r - p.i * p.i + c.r;
		p.i = 2 * p.r * p.i + c.i;
		p.r = tmp;
		iter++;
	}
	return iter;
}

t_complex warp_coord_to_complex(int x, int y, t_data *data)
{
	t_complex point;

	point.r = data->start_r + ((long double) (x) * (data->stop_r - data->start_r)) / data->size_x;
	point.i = data->start_i + ((long double) (y) * (data->stop_i - data->start_i)) / data->size_y;
	return (point);
}

static int is_in_cardiod(t_complex c)
{
	long double	tmp;
	tmp = (((4.0L * (c.r * c.r))-(2.0L*c.r)+(1.0L/4.0L))) + (c.i * c.i);
	if (tmp * (tmp + (c.r - (1.0L / 4.0L))) > ((c.i*c.i) / 4.0L))
		return 0;
	else return 1;
}

void mandelbrot_escape(t_data *data)
{
	t_complex	c;
	int 		x;
	int 		y;
	int 		color;

	y = 0;
	while (y++ < data->size_y - 1)
	{
		x = 0;
		while (x++ < data->size_x - 1)
		{
			c = warp_coord_to_complex(x, y, data);
            if (is_in_cardiod(c) == 0)
            	color = calc_escape_value(data, c, 0);
			else
            	color = data->max_iter;
			put_pixel_2_img(data->img_buffer, x, y, get_color(data, color));
		}
	}
}