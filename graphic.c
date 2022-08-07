/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgarcia <jgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:39:43 by jgarcia           #+#    #+#             */
/*   Updated: 2022/07/27 12:40:03 by jgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void put_pixel_2_img(t_buffer *img,int x, int y, int color)
{
	char *dest;

	dest = img->address + (y * img->line_length + x * (img->bit_per_pixel / 8));
	*(unsigned int *)dest = color;
}

void clear_buffer(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < data->size_y)
	{
		x = 0;
		while (x < data->size_x)
		{
			put_pixel_2_img(data->img_buffer,x,y,0xffffff);
			x ++;
		}
		y ++;
	}
}
int rgb_to_mlx_color(int red, int green,int blue)
{
	int	color;

	color = red * 0x10000 + green * 0x100 + blue;
	return (color);
}

int	hsv_to_rgb(int hue, int sat, int value)
{
	double	x;
	//double 	m;
	double	c;
	int		red;
	int 	green;
	int 	blue;
	double 	r;
	double 	g;
	double	b;

	(void) value;
	(void) sat;
	c = ((double)value / 100) * ((double)sat / 100);
	x = c * (1 - abs((hue / 60) % 2) - 1);
	//m = 1.0; //((double) value / 100) - c;
	if (hue >= 0 && hue < 60)
	{
		r = c;
		g = x;
		b = 0;
	}
	else if (hue >= 60 && hue < 120)
	{
		r = x;
		g =c;
		b = 0;
	}
	else if (hue >= 120 && hue < 180)
	{
		r = 0;
		g = c;
		b = x;
	}
	else if (hue >= 180 && hue < 240)
	{
		r = 0;
		g = x;
		b = c;
	}
	else if (hue >= 240 && hue < 300)
	{
		r = x;
		g = 0;
		b = c;
	}
	else if (hue >= 300 && hue <= 360)
	{
		r = c;
		g = 0;
		b = x;
	}
	red = (int) round(r  * 255);
	green = (int) round(g  * 255);
	blue = (int) round(b * 255);
	return (rgb_to_mlx_color(red,green,blue));
}

int	render(t_data *data)
{
	if (data->redraw == 1)
	{
		clear_buffer(data);
        (*data->algorithm)(data);
		mlx_put_image_to_window(data->mlx,
								data->mlx_win,
								data->img_buffer->img,
								0, 0);
		// TODO putstring with current param
		// TODO implement ITOA
	}
	return (0);
}