/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_escape.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:44:13 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 00:43:39 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*******************************************************************************
 * iterate mandelbrot function until it escape to infinity for point p         *
 * @return number of iteration it took for function to break stability         *
 ******************************************************************************/

static int	calc_escape_value(t_data *data, t_complex c)
{
	int			iter;
	long double	tmp;
	t_complex	p;

	iter = 0;
	p = c;
	while ((p.r * p.r + p.i * p.i <= 2) && (iter < data->max_iter))
	{
		tmp = p.r * p.r - p.i * p.i + c.r;
		p.i = 2 * p.r * p.i + c.i;
		p.r = tmp;
		iter++;
	}
	return (iter);
}

/*******************************************************************************
 * optimisation : determine if the point c is in the first order cardiod of    *
 * the mandelbrot set                                                          *
 * @return 0 if not in first order cardioid 1 if in cardioid                   *
 ******************************************************************************/

static int	is_in_cardiod(t_complex c)
{
	long double	tmp;

	tmp = (((4.0L * (c.r * c.r)) - (2.0L * c.r) + (1.0L / 4.0L))) + (c.i * c.i);
	if (tmp * (tmp + (c.r - (1.0L / 4.0L))) > ((c.i * c.i) / 4.0L))
		return (0);
	else
		return (1);
}

/*******************************************************************************
 * map each pixel to a point in the complex point determined by simulation     *
 * parameters in data structure and check if the point is in mandelbrot set    *
 ******************************************************************************/

void	mandelbrot_escape(t_data *data)
{
	t_complex	c;
	int			x;
	int			y;
	int			color;

	y = 0;
	while (y ++ < data->size_y - 1)
	{
		x = 0;
		while (x ++ < data->size_x - 1)
		{
			c = warp_coord_to_complex(x, y, data);
			if (is_in_cardiod(c) == 0)
				color = calc_escape_value(data, c);
			else
				color = data->max_iter;
			put_pixel_2_img(data->img_buffer, x, y,
				get_color(data, color));
		}
	}
}