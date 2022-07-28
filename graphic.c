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


int	render(t_data *data)
{
	static int frame = 0;

	if (frame == 0)
	{
		clear_buffer(data);
		frame ++;
	}
	else if (frame == 1)
	{
		render_escape(data);
		frame ++;
	}
	else if (frame == 2)
	{
		mlx_put_image_to_window(data->mlx,
								data->mlx_win,
								data->img_buffer->img,
								0, 0);
		frame = 0;
	}
	return (0);
}