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
			put_pixel_2_img(data->img_buffer,x,y,0);
			x ++;
		}
		y ++;
	}
}
int get_mlx_color(double red, double green, double blue)
{
	int	r;
	int g;
	int b;

	r = (int) round(red  * 255);
	g = (int) round(green  * 255);
	b = (int) round(blue * 255);
	return (r * 0x10000 + g * 0x100 + b);
}

int	hsv_to_rgb(int hue, int sat, int value)
{
	double	x;
	double	c;
	int 	color;

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

int	render(t_data *data)
{
	if (data->redraw == 1)
	{
		data->redraw = 0;
		clear_buffer(data);
		// TODO array of animation function
        if (data->algorithm != NULL)
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