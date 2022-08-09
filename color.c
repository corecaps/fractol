/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 01:37:09 by jgarcia           #+#    #+#             */
/*   Updated: 2022/08/10 01:37:22 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*******************************************************************************
 * translate double value (between 0.0 and 1.0) to a single color value int    *
 * @return a valid mlx color value used by put pixel 2 img                     *
 ******************************************************************************/

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

/*******************************************************************************
 * transform a color described by hue (in degre) sat (%) value(%) to rgb in    *
 * single int                                                                  *
 * @return a valid color that can be used by put pixel 2 img                   *
 ******************************************************************************/

int	hsv_to_rgb(int hue, int sat, int value)
{
	double	x;
	double	c;
	int		color;

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