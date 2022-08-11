/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:37:09 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/11 14:58:06 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/******************************************************************************
 * determine color value with hsv to rgb from iteration number                *
 * used by julia and mandelbrot set                                           *
 * @return rgb in a single int value                                          *
 *****************************************************************************/

int	get_color(const t_data *data, int iter)
{
	int	color;

	if (iter <= 3)
		iter = 3;
	if (iter == data->max_iter)
		iter = 0;
	if (iter > 0)
	{
		color = hsv_to_rgb(((iter)
					* 360) / data->max_iter,
				100,
				(int) round((pow(iter, 0.5) * 100)
					/ pow(data->max_iter, 0.5)), data->color_offset);
	}
	else
		color = 0;
	return (color);
}

/******************************************************************************
 * translate double value (between 0.0 and 1.0) to a single color value int   *
 * @return a valid mlx color value used by put pixel 2 img                    *
 *****************************************************************************/

int	get_mlx_color(double red, double green, double blue)
{
	int	r;
	int	g;
	int	b;

	r = (int) round(red * 255);
	g = (int) round(green * 255);
	b = (int) round(blue * 255);
	return (r * 0x10000 + g * 0x100 + b);
}

/******************************************************************************
 * transform a color described by hue (in degre) sat (%) value(%) to rgb in   *
 * single int                                                                 *
 * @return a valid color that can be used by put pixel 2 img                  *
 *****************************************************************************/

int	hsv_to_rgb(int hue, int sat, int value, int offset)
{
	double	x;
	double	c;
	int		color;

	hue = (hue + offset) % 360;
	c = ((double)value / 100) * ((double)sat / 100);
	x = c * (1 - abs((hue / 60) % 2) - 1);
	if (hue >= 0 && hue < 60)
		color = get_mlx_color(c, x, 0);
	else if (hue >= 60 && hue < 120)
		color = get_mlx_color(x, c, 0);
	else if (hue >= 120 && hue < 180)
		color = get_mlx_color(0, c, x);
	else if (hue >= 180 && hue < 240)
		color = get_mlx_color(0, x, c);
	else if (hue >= 240 && hue < 300)
		color = get_mlx_color(x, 0, c);
	else
		color = get_mlx_color(c, 0, x);
	return (color);
}
